#!/usr/bin/env python3
"""Every settings handler must be reachable through the shell service router."""
from pathlib import Path
import re
import unittest

ROOT = Path(__file__).resolve().parents[2]
SHELL = ROOT / 'overlay/chrome/browser/ui/ohos'


class SettingsRoutingTest(unittest.TestCase):
    def test_all_settings_commands_reach_the_settings_dispatcher(self):
        settings = (SHELL / 'shell_settings_ohos.cc').read_text()
        services = (SHELL / 'shell_services_ohos.cc').read_text()
        handlers = re.findall(r'\{"([^"]+)",\s*&[\w:]+\}', settings)
        routes = re.findall(r'\{"([^"]+)",\s*&HandleSettingsCommand\}', services)
        self.assertTrue(handlers, 'No settings command handlers found')
        self.assertEqual(len(handlers), len(set(handlers)), 'Duplicate settings handlers')
        self.assertEqual(len(routes), len(set(routes)), 'Duplicate settings routes')
        self.assertEqual(set(handlers), set(routes),
                         'A settings handler is unreachable or a service route has no handler')


if __name__ == '__main__':
    unittest.main()
