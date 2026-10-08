#!/usr/bin/env python3
"""Exercise the test server over HTTP, without connecting to a device."""

import functools
import http.client
from http.server import ThreadingHTTPServer
import importlib.util
from pathlib import Path
import tempfile
import threading
import unittest

spec = importlib.util.spec_from_file_location(
    "test_page_server", Path(__file__).resolve().parents[1] / "serve-test-pages.py")
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class QuietHandler(module.RangeRequestHandler):
    def log_message(self, *_args):
        pass


class RangeServerTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.directory = tempfile.TemporaryDirectory()
        cls.payload = bytes(range(256)) * 1024
        root = Path(cls.directory.name)
        (root / "video.mp4").write_bytes(cls.payload)
        (root / "empty.mp4").touch()
        (root / "index.html").write_text("test page")
        cls.server = ThreadingHTTPServer(("127.0.0.1", 0), functools.partial(
            QuietHandler, directory=cls.directory.name))
        cls.thread = threading.Thread(target=cls.server.serve_forever, daemon=True)
        cls.thread.start()

    @classmethod
    def tearDownClass(cls):
        cls.server.shutdown()
        cls.server.server_close()
        cls.thread.join()
        cls.directory.cleanup()

    def request(self, headers=None, method="GET", path="/video.mp4"):
        connection = http.client.HTTPConnection(*self.server.server_address, timeout=5)
        try:
            connection.request(method, path, headers=headers or {})
            response = connection.getresponse()
            return response.status, dict(response.getheaders()), response.read()
        finally:
            connection.close()

    def test_full_file_and_head(self):
        for method in ("GET", "HEAD"):
            status, headers, body = self.request(method=method)
            self.assertEqual(status, 200)
            self.assertEqual(headers["Accept-Ranges"], "bytes")
            self.assertEqual(int(headers["Content-Length"]), len(self.payload))
            self.assertEqual(body, self.payload if method == "GET" else b"")

    def test_seek_ranges(self):
        size = len(self.payload)
        for value, start, end in (("bytes=0-", 0, size - 1),
                                  ("bytes=10240-", 10240, size - 1),
                                  ("bytes=111-777", 111, 777),
                                  ("bytes=-19", size - 19, size - 1),
                                  ("bytes=262140-999999", size - 4, size - 1),
                                  ("bytes=-999999", 0, size - 1)):
            with self.subTest(value=value):
                status, headers, body = self.request({"Range": value})
                self.assertEqual(status, 206)
                self.assertEqual(headers["Content-Range"], f"bytes {start}-{end}/{size}")
                self.assertEqual(int(headers["Content-Length"]), end - start + 1)
                self.assertEqual(body, self.payload[start:end + 1])

    def test_unsatisfiable(self):
        for value in ("bytes=999999-", "bytes=20-10", "bytes=-0"):
            status, headers, body = self.request({"Range": value})
            self.assertEqual(status, 416)
            self.assertEqual(headers["Content-Range"], f"bytes */{len(self.payload)}")
            self.assertEqual(body, b"")
        self.assertEqual(self.request({"Range": "bytes=0-"}, path="/empty.mp4")[0], 416)

    def test_invalid_or_multiple_ranges_are_ignored(self):
        for value in ("bytes=1-2,5-6", "bytes=-", "bytes=abc", "items=0-1"):
            status, _, body = self.request({"Range": value})
            self.assertEqual(status, 200)
            self.assertEqual(body, self.payload)

    def test_validators_and_pages(self):
        _, headers, _ = self.request(method="HEAD")
        modified = headers["Last-Modified"]
        self.assertEqual(self.request({"Range": "bytes=10-20", "If-Range": modified})[0], 206)
        for validator in ('"unknown-etag"', "Mon, 01 Jan 1990 00:00:00 GMT", "bad"):
            status, _, body = self.request({"Range": "bytes=10-20", "If-Range": validator})
            self.assertEqual(status, 200)
            self.assertEqual(body, self.payload)
        status, _, body = self.request({"Range": "bytes=10-20", "If-Modified-Since": modified})
        self.assertEqual((status, body), (304, b""))
        self.assertEqual(self.request(path="/")[2], b"test page")
        self.assertEqual(self.request({"Range": "bytes=0-"}, path="/missing.mp4")[0], 404)


if __name__ == "__main__":
    unittest.main()
