import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import test from 'node:test';
import vm from 'node:vm';

const source = readFileSync(new URL('../../overlay/chrome/browser/ui/ohos/aura_shell_runtime_bridge.cc', import.meta.url), 'utf8');
const script = source.match(/kDisplayProbe\[\] = uR"JS\(([\s\S]*?)\)JS";/)[1];
function probe({ fullscreen = false, viewport = true, root = true } = {}) {
  const video = { videoWidth: 1920, videoHeight: 1080,
    getBoundingClientRect: () => ({ x: 70, y: 0, width: 670, height: 377 }) };
  const document = {
    documentElement: root ? { clientWidth: 376, clientHeight: 700, scrollWidth: 600, scrollHeight: 2000 } : null,
    fullscreenElement: fullscreen ? { querySelector: () => video, getBoundingClientRect: () => ({ x: -20, y: 10, width: 700, height: 376 }) } : null,
    querySelector(selector) { if (selector === 'video') return video; assert.equal(selector, 'meta[name="viewport" i]'); return {}; }
  };
  // Access to page content/URL is a test failure, including future probe additions.
  for (const key of ['URL', 'title', 'body', 'cookie', 'location']) {
    Object.defineProperty(document, key, { get() { throw Error('private field read: ' + key); } });
  }
  return vm.runInNewContext(script, { document,
    window: { innerWidth: 376, innerHeight: 700, outerWidth: 376, outerHeight: 809, devicePixelRatio: 3.5,
      visualViewport: viewport ? { width: 300, height: 550, scale: 1.25, offsetLeft: 30, offsetTop: 0 } : null },
    screen: { width: 376, height: 809 }
  });
}

test('fixed geometry probe identifies overflow, pinch zoom, and fullscreen offset without content', () => {
  const r = probe({ fullscreen: true });
  assert.equal(r.rootScrollWidthCss > r.rootClientWidthCss, true);
  assert.equal(r.visualScale, 1.25);
  assert.equal(r.videoWidthCss, 670);
  assert.equal(r.videoXCss, 70);
  assert.equal(r.videoIntrinsicWidth, 1920);
  assert.equal(r.devicePixelRatio, 3.5);
  assert.equal(r.fullscreenXCss, -20);
  assert.equal(r.fullscreenWidthCss, 700);
  assert.equal(r.domFullscreen, true);
  assert.equal(r.viewportMetaPresent, true);
  for (const value of Object.values(r)) assert.ok(typeof value === 'number' || typeof value === 'boolean');
});

test('probe handles absent DOM/visual viewport/fullscreen and native boundary validates document and values', () => {
  const r = probe({ root: false, viewport: false });
  assert.equal(r.rootClientWidthCss, 0);
  assert.equal(r.visualViewportAvailable, false);
  assert.equal(r.visualScale, 0);
  assert.equal(r.domFullscreen, false);
  assert.equal(r.fullscreenWidthCss, 0);
  const handler = source.slice(source.indexOf('if (*name == "getPageDisplayDiagnostics")'), source.indexOf('if (*name == "getPageText"'));
  assert.match(handler, /target != active/);
  assert.match(handler, /GetWeakDocumentPtr\(\)/);
  assert.match(handler, /active->GetPrimaryMainFrame\(\) != frame/);
  assert.match(handler, /std::isfinite\(\*value\)/);
  assert.match(handler, /ISOLATED_WORLD_ID_CHROME_INTERNAL/);
  for (const key of Object.keys(r)) assert.ok(handler.includes('"' + key + '"'), 'allowlisted ' + key);
});
