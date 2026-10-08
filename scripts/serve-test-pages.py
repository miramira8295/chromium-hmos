#!/usr/bin/env python3
"""Serve local test pages and seekable media with HTTP byte ranges."""

import argparse
import email.utils
import functools
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
import os
from pathlib import Path
import re


class RangeRequestHandler(SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header("Accept-Ranges", "bytes")
        super().end_headers()

    def send_head(self):
        self.byte_range = None
        value = self.headers.get("Range", "")
        match = re.fullmatch(r"bytes=(\d*)-(\d*)", value.strip())
        path = self.translate_path(self.path)
        # Multiple/invalid ranges may be ignored (RFC 9110). Keep stdlib's
        # directory redirects, listings, HEAD and ordinary conditional GETs.
        if (self.command != "GET" or not match or not any(match.groups())
                or os.path.isdir(path)):
            return super().send_head()
        try:
            source = open(path, "rb")
        except OSError:
            self.send_error(404, "File not found")
            return None
        try:
            stat = os.fstat(source.fileno())
            if_range = self.headers.get("If-Range")
            if if_range:
                # We provide Last-Modified, not ETags. An unknown validator
                # must return the entire representation, never a partial file.
                try:
                    date = email.utils.parsedate_to_datetime(if_range)
                    matches = int(date.timestamp()) == int(stat.st_mtime)
                except (ValueError, TypeError, OverflowError):
                    matches = False
                if not matches:
                    source.close()
                    return super().send_head()
            if_modified = self.headers.get("If-Modified-Since")
            if if_modified and not self.headers.get("If-None-Match"):
                try:
                    date = email.utils.parsedate_to_datetime(if_modified)
                    unmodified = int(stat.st_mtime) <= int(date.timestamp())
                except (ValueError, TypeError, OverflowError):
                    unmodified = False
                if unmodified:
                    source.close()
                    self.send_response(304)
                    self.end_headers()
                    return None
            size = stat.st_size
            first, last = match.groups()
            if first:
                start = int(first)
                end = min(int(last), size - 1) if last else size - 1
            else:
                start = max(size - int(last), 0)
                end = size - 1
            if start >= size or start > end:
                source.close()
                self.send_response(416)
                self.send_header("Content-Range", f"bytes */{size}")
                self.send_header("Content-Length", "0")
                self.end_headers()
                return None
            self.byte_range = (start, end)
            self.send_response(206)
            self.send_header("Content-Type", self.guess_type(path))
            self.send_header("Content-Range", f"bytes {start}-{end}/{size}")
            self.send_header("Content-Length", str(end - start + 1))
            self.send_header("Last-Modified", self.date_time_string(stat.st_mtime))
            self.end_headers()
            source.seek(start)
            return source
        except Exception:
            source.close()
            raise

    def copyfile(self, source, outputfile):
        if self.byte_range is None:
            return super().copyfile(source, outputfile)
        start, end = self.byte_range
        remaining = end - start + 1
        while remaining:
            chunk = source.read(min(remaining, 64 * 1024))
            if not chunk:
                break
            outputfile.write(chunk)
            remaining -= len(chunk)

    def do_GET(self):
        try:
            super().do_GET()
        except (BrokenPipeError, ConnectionResetError):
            # Seeking/closing a video routinely cancels the previous request.
            pass


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", type=int, default=8080)
    parser.add_argument("--bind", default="127.0.0.1")
    parser.add_argument("--directory", type=Path,
                        default=Path(__file__).resolve().parents[1] / "docs/test-pages")
    args = parser.parse_args()
    handler = functools.partial(RangeRequestHandler, directory=str(args.directory))
    with ThreadingHTTPServer((args.bind, args.port), handler) as server:
        print(f"Serving {args.directory} at http://{args.bind}:{args.port}/ "
              "(byte ranges enabled)", flush=True)
        try:
            server.serve_forever()
        except KeyboardInterrupt:
            pass


if __name__ == "__main__":
    main()
