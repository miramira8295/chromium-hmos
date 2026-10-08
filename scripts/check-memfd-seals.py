#!/usr/bin/env python3
"""Check the Linux kernel contract used by OHOS read-only memfd conversion.

This exercises real syscalls, including reopening a read-only fd as writable.
It does not substitute for Chromium unit tests or HarmonyOS SELinux testing.
"""

import contextlib
import ctypes
import errno
import fcntl
import mmap
import os
import platform
import subprocess
import sys


FUTURE_WRITE = getattr(fcntl, "F_SEAL_FUTURE_WRITE", 0x0010)
SIZE_SEALS = fcntl.F_SEAL_SHRINK | fcntl.F_SEAL_GROW
SIZE = mmap.PAGESIZE


def expect_denied(operation, allowed=(errno.EPERM, errno.EACCES)):
    try:
        result = operation()
    except OSError as error:
        assert error.errno in allowed, error
        return
    if hasattr(result, "close"):
        result.close()
    raise AssertionError("operation unexpectedly succeeded")


def fd_in(stack, fd):
    stack.callback(os.close, fd)
    return fd


def create_region(stack):
    fd = fd_in(stack, os.memfd_create(
        "ohos-seal-test", os.MFD_CLOEXEC | os.MFD_ALLOW_SEALING))
    os.ftruncate(fd, SIZE)
    fcntl.fcntl(fd, fcntl.F_ADD_SEALS, SIZE_SEALS)
    return fd


def map_shared(fd, writable=True):
    protection = mmap.PROT_READ | (mmap.PROT_WRITE if writable else 0)
    return mmap.mmap(fd, SIZE, flags=mmap.MAP_SHARED, prot=protection)


def check_readonly_reopen():
    with contextlib.ExitStack() as stack:
        fd = create_region(stack)
        writer = stack.enter_context(map_shared(fd))
        readonly = fd_in(stack, os.open(f"/proc/self/fd/{fd}", os.O_RDONLY))

        # Negative control: O_RDONLY plus size seals alone is insufficient.
        reopened = fd_in(stack, os.open(f"/proc/self/fd/{readonly}", os.O_RDWR))
        assert os.pwrite(reopened, b"A", 0) == 1
        assert writer[0] == ord("A")

        fcntl.fcntl(fd, fcntl.F_ADD_SEALS, FUTURE_WRITE | fcntl.F_SEAL_SEAL)
        # A receiver may reopen after conversion too. Even a same-UID receiver
        # must not recover write access; no chmod or DAC denial is involved.
        receiver = fd_in(stack, os.open(f"/proc/self/fd/{readonly}", os.O_RDWR))
        for handle in (reopened, receiver):
            expect_denied(lambda: os.pwrite(handle, b"B", 0))
            expect_denied(lambda: map_shared(handle))
            expect_denied(lambda: os.ftruncate(handle, 0))
            expect_denied(lambda: os.ftruncate(handle, SIZE * 2))

        reader = stack.enter_context(map_shared(readonly, writable=False))
        writer[0] = ord("C")
        assert reader[0] == ord("C"), "existing producer mapping stopped working"

        # A read-only mapping of the reopened O_RDWR fd cannot be upgraded.
        libc = ctypes.CDLL(None, use_errno=True)
        libc.mmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int,
                              ctypes.c_int, ctypes.c_int, ctypes.c_long]
        libc.mmap.restype = ctypes.c_void_p
        libc.mprotect.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int]
        libc.munmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t]
        address = libc.mmap(None, SIZE, mmap.PROT_READ, mmap.MAP_SHARED, receiver, 0)
        assert address != ctypes.c_void_p(-1).value, ctypes.get_errno()
        try:
            assert libc.mprotect(address, SIZE, mmap.PROT_READ | mmap.PROT_WRITE) == -1
            assert ctypes.get_errno() in (errno.EACCES, errno.EPERM)
        finally:
            assert libc.munmap(address, SIZE) == 0
    print("PASS: readonly reopen/write/mmap/mprotect denied; existing writer works")


def check_unsafe_and_failed_conversion():
    with contextlib.ExitStack() as stack:
        fd = create_region(stack)
        fcntl.fcntl(fd, fcntl.F_ADD_SEALS, fcntl.F_SEAL_SEAL)
        expect_denied(lambda: fcntl.fcntl(fd, fcntl.F_ADD_SEALS, FUTURE_WRITE))
        writer = stack.enter_context(map_shared(fd))
        second_writer = stack.enter_context(map_shared(fd))
        writer[0] = ord("D")
        assert second_writer[0] == ord("D")
        assert os.pwrite(fd, b"E", 0) == 1
        assert writer[0] == ord("E")
    print("PASS: Unsafe permits future writers and rejects added write seals")


def check_sealed_receiver(fd):
    # Executed in a fresh process with only the FD, not the producer mapping.
    assert fcntl.fcntl(fd, fcntl.F_GETFL) & os.O_ACCMODE == os.O_RDWR
    required = SIZE_SEALS | FUTURE_WRITE | fcntl.F_SEAL_SEAL
    assert fcntl.fcntl(fd, fcntl.F_GET_SEALS) & required == required
    with map_shared(fd, writable=False) as reader:
        assert reader[0] == ord("P")
    expect_denied(lambda: os.pwrite(fd, b"X", 0))
    expect_denied(lambda: map_shared(fd))
    expect_denied(lambda: os.ftruncate(fd, 0))
    expect_denied(lambda: os.ftruncate(fd, SIZE * 2))
    libc = ctypes.CDLL(None, use_errno=True)
    libc.mmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int,
                         ctypes.c_int, ctypes.c_int, ctypes.c_long]
    libc.mmap.restype = ctypes.c_void_p
    libc.mprotect.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int]
    libc.munmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t]
    address = libc.mmap(None, SIZE, mmap.PROT_READ, mmap.MAP_SHARED, fd, 0)
    assert address != ctypes.c_void_p(-1).value, ctypes.get_errno()
    try:
        assert libc.mprotect(address, SIZE, mmap.PROT_READ | mmap.PROT_WRITE) == -1
        assert ctypes.get_errno() in (errno.EACCES, errno.EPERM)
    finally:
        assert libc.munmap(address, SIZE) == 0


def check_no_procfs_conversion():
    with contextlib.ExitStack() as stack:
        fd = create_region(stack)
        paired = fd_in(stack, fcntl.fcntl(fd, fcntl.F_DUPFD_CLOEXEC, 0))
        assert not os.get_inheritable(paired)
        # The duplicate is writable before conversion; it must never be
        # accepted as a read-only handle in this state.
        assert os.pwrite(paired, b"W", 0) == 1
        writer = stack.enter_context(map_shared(fd))
        fcntl.fcntl(fd, fcntl.F_ADD_SEALS, FUTURE_WRITE | fcntl.F_SEAL_SEAL)
        writer[0] = ord("P")
        subprocess.run([sys.executable, __file__, "--sealed-receiver", str(paired)],
                       pass_fds=(paired,), check=True, timeout=20)
        writer[0] = ord("Q")
        with map_shared(paired, writable=False) as reader:
            assert reader[0] == ord("Q")
    print("PASS: no-procfs dup conversion; receiver cannot write; producer still can")


def check_import_without_getattr(fd, unrelated):
    # Model a target policy which allows memfd/fcntl/mmap but denies getattr.
    # Apply the filter only in this disposable receiver process.
    numbers = {
        "x86_64": (4, 5, 6, 262, 332),  # stat/fstat/lstat/newfstatat/statx
        "aarch64": (79, 80, 291),
    }[platform.machine()]

    class Filter(ctypes.Structure):
        _fields_ = [("code", ctypes.c_ushort), ("jt", ctypes.c_ubyte),
                    ("jf", ctypes.c_ubyte), ("k", ctypes.c_uint)]

    class Program(ctypes.Structure):
        _fields_ = [("len", ctypes.c_ushort), ("filter", ctypes.POINTER(Filter))]

    instructions = [Filter(0x20, 0, 0, 0)]  # Load seccomp_data.nr.
    for number in numbers:
        instructions += [Filter(0x15, 0, 1, number),
                         Filter(0x06, 0, 0, 0x00050000 | errno.EACCES)]
    instructions.append(Filter(0x06, 0, 0, 0x7fff0000))  # Allow other calls.
    filters = (Filter * len(instructions))(*instructions)
    program = Program(len(instructions), filters)
    libc = ctypes.CDLL(None, use_errno=True)
    libc.mmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_int,
                         ctypes.c_int, ctypes.c_int, ctypes.c_long]
    libc.mmap.restype = ctypes.c_void_p
    libc.munmap.argtypes = [ctypes.c_void_p, ctypes.c_size_t]
    assert libc.prctl(38, 1, 0, 0, 0) == 0, ctypes.get_errno()
    assert libc.prctl(22, 2, ctypes.byref(program), 0, 0) == 0, ctypes.get_errno()
    expect_denied(lambda: os.fstat(fd), allowed=(errno.EACCES,))
    expect_denied(lambda: os.fstat(unrelated), allowed=(errno.EACCES,))

    # Discard the supplied paired inode. Rebuild the conversion FD from the
    # writable primary, just as an importer must do before read-only sealing.
    paired = fcntl.fcntl(fd, fcntl.F_DUPFD_CLOEXEC, 0)
    assert fcntl.fcntl(fd, fcntl.F_GETFL) & os.O_ACCMODE == os.O_RDWR
    assert fcntl.fcntl(fd, fcntl.F_GET_SEALS) == SIZE_SEALS
    address = libc.mmap(None, SIZE, mmap.PROT_READ | mmap.PROT_WRITE,
                        mmap.MAP_SHARED, fd, 0)
    assert address != ctypes.c_void_p(-1).value, ctypes.get_errno()
    try:
        fcntl.fcntl(fd, fcntl.F_ADD_SEALS, FUTURE_WRITE | fcntl.F_SEAL_SEAL)
        ctypes.c_ubyte.from_address(address).value = ord("R")
        assert os.pread(paired, 1, 0) == b"R"
        assert os.pread(unrelated, 1, 0) == b"X"
        assert fcntl.fcntl(unrelated, fcntl.F_GET_SEALS) == SIZE_SEALS
        expect_denied(lambda: os.pwrite(paired, b"Y", 0))
        readonly = libc.mmap(None, SIZE, mmap.PROT_READ, mmap.MAP_SHARED, paired, 0)
        assert readonly != ctypes.c_void_p(-1).value, ctypes.get_errno()
        try:
            assert ctypes.c_ubyte.from_address(readonly).value == ord("R")
        finally:
            assert libc.munmap(readonly, SIZE) == 0
    finally:
        assert libc.munmap(address, SIZE) == 0
        os.close(paired)


def check_writable_import():
    with contextlib.ExitStack() as stack:
        fd = create_region(stack)
        unrelated = create_region(stack)
        os.pwrite(unrelated, b"X", 0)
        subprocess.run([sys.executable, __file__, "--getattr-denied-receiver",
                        str(fd), str(unrelated)], pass_fds=(fd, unrelated),
                       check=True, timeout=20)
        assert os.pread(fd, 1, 0) == b"R"
    print("PASS: writable import with getattr denied; substituted inode not used")


if __name__ == "__main__":
    if len(sys.argv) == 3 and sys.argv[1] == "--sealed-receiver":
        check_sealed_receiver(int(sys.argv[2]))
    elif len(sys.argv) == 4 and sys.argv[1] == "--getattr-denied-receiver":
        check_import_without_getattr(int(sys.argv[2]), int(sys.argv[3]))
    else:
        check_readonly_reopen()
        check_unsafe_and_failed_conversion()
        check_no_procfs_conversion()
        check_writable_import()
