// Device regression: CDP_URL=http://127.0.0.1:19571 EXPECTED_FONT_SCALE=1.45 node ...
// Add --fullscreen to also require a completed native fullscreen transition.
// Creates a disposable test tab; never reads or navigates an existing user tab.
import assert from 'node:assert/strict';
const endpoint = process.env.CDP_URL ?? 'http://127.0.0.1:19571';
const expected = Number(process.env.EXPECTED_FONT_SCALE ?? '1.45');
const observe = process.argv.includes('--observe');
const fullscreen = process.argv.includes('--fullscreen');
const version = await fetch(`${endpoint}/json/version`, { signal: AbortSignal.timeout(8000) }).then(r => r.json());
const socket = new WebSocket(version.webSocketDebuggerUrl);
await new Promise((resolve, reject) => { socket.onopen = resolve; socket.onerror = reject; });
let sequence = 0;
const pending = new Map();
socket.onmessage = ({ data }) => {
  const message = JSON.parse(data);
  const request = pending.get(message.id);
  if (!request) return;
  pending.delete(message.id);
  clearTimeout(request.timer);
  if (message.error) request.reject(Error(JSON.stringify(message.error)));
  else request.resolve(message.result);
};
function call(method, params = {}, sessionId) {
  return new Promise((resolve, reject) => {
    const id = ++sequence;
    const timer = setTimeout(() => { pending.delete(id); reject(Error(`Timeout: ${method}`)); }, 15000);
    pending.set(id, { resolve, reject, timer });
    socket.send(JSON.stringify({ id, method, params, ...(sessionId ? { sessionId } : {}) }));
  });
}
function assertRect(actual, expectedRect, label) {
  for (const dimension of ['width', 'height'])
    assert.ok(Math.abs(actual[dimension] - expectedRect[dimension]) < 0.05,
      `${label} ${dimension}: ${actual[dimension]} vs ${expectedRect[dimension]}`);
}
let targetId;
try {
  ({ targetId } = await call('Target.createTarget', { url: 'about:blank', background: true }));
  await call('Target.activateTarget', { targetId });
  const { sessionId } = await call('Target.attachToTarget', { targetId, flatten: true });
  async function evaluate(expression, userGesture = false) {
    if (process.env.DEBUG_FONT_TEST) console.error('evaluate:', expression.slice(0, 160));
    const r = await call('Runtime.evaluate', { expression, awaitPromise: true, returnByValue: true, userGesture }, sessionId);
    if (r.exceptionDetails) throw Error(JSON.stringify(r.exceptionDetails));
    return r.result.value;
  }
  const html = `<!doctype html><meta name="viewport" content="width=device-width,initial-scale=1">
<style>body{margin:0}#text{display:inline-block;font:20px/20px sans-serif}
#image{width:120px;height:80px}#box{width:160px;height:90px}video{width:100%;height:100%}
#box:fullscreen{width:100%;height:100%;background:black}</style>
<span id="text">Text scaling</span>
<img id="image" src="data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='120' height='80'%3E%3Crect width='120' height='80' fill='teal'/%3E%3C/svg%3E">
<div id="box"><video></video></div>
<iframe id="child" srcdoc="<span id='text' style='display:inline-block;font:20px/20px sans-serif'>Child text</span>"></iframe>
<script>
window.sample=()=>{
 const rect=id=>{const r=document.querySelector(id).getBoundingClientRect();return {width:r.width,height:r.height}};
 return {text:rect('#text'),image:rect('#image'),box:rect('#box'),video:rect('video'),
 viewport:{width:innerWidth,height:innerHeight},dpr:devicePixelRatio,
 childHeight:document.querySelector('#child').contentDocument.querySelector('#text').getBoundingClientRect().height};
};
window.setMeta=(on)=>{
 let m=document.querySelector('meta[name="text-scale"]');
 if(on&&!m){m=document.createElement('meta');m.name='text-scale';m.content='scale';document.head.append(m)}
 if(!on&&m)m.remove();
 return new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(()=>r(sample()))));
};
</script>`;
  await call('Page.enable', {}, sessionId);
  await call('Page.navigate', { url: `data:text/html;charset=utf-8,${encodeURIComponent(html)}` }, sessionId);
  // Navigation can replace the initial execution context after navigate returns.
  const deadline = Date.now() + 15000;
  while (true) {
    const ready = await evaluate(`document.readyState==='complete' && typeof setMeta==='function' &&
      !!document.querySelector('#child').contentDocument?.querySelector('#text')`).catch(() => false);
    if (ready) break;
    assert.ok(Date.now() < deadline, 'test document did not finish loading');
    await new Promise(resolve => setTimeout(resolve, 100));
  }
  const initial = await evaluate('sample()');
  const baseline = await evaluate('setMeta(true)');
  const ordinary = await evaluate('setMeta(false)');
  const adaptedAgain = await evaluate('setMeta(true)');
  await evaluate('setMeta(false)');
  const result = { browser: version.Browser, expected, initial, baseline, ordinary, adaptedAgain,
    textRatio: ordinary.text.height / baseline.text.height };
  if (!observe) {
    assert.ok(Math.abs(initial.text.height / baseline.text.height - expected) < 0.02, 'new document applies text scaling');
    assert.ok(Math.abs(result.textRatio - expected) < 0.02, `text ratio ${result.textRatio}, expected ${expected}`);
    assertRect(ordinary.image, baseline.image, 'fixed image dimensions');
    assertRect(ordinary.video, baseline.video, 'fixed video dimensions');
    assert.deepEqual(ordinary.viewport, baseline.viewport, 'layout viewport');
    assert.equal(ordinary.dpr, baseline.dpr, 'device/page scale');
    assert.ok(Math.abs(adaptedAgain.text.height - baseline.text.height) < 0.1, 'meta opt-in must not double-scale');
    assert.ok(Math.abs(baseline.childHeight / baseline.text.height - expected) < 0.02, 'ordinary child of meta parent');
    assert.ok(Math.abs(ordinary.childHeight - baseline.childHeight) < 0.1, 'child must not inherit parent opt-in');
    if (fullscreen) {
      await call('Target.activateTarget', { targetId });
      result.fullscreen = await evaluate(`(async()=>{await document.querySelector('#box').requestFullscreen();
        await new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)));return sample()})()`, true);
      await evaluate('document.exitFullscreen()', true);
      assert.ok(Math.abs(result.fullscreen.box.width - result.fullscreen.viewport.width) <= 1, 'fullscreen width');
      assert.ok(Math.abs(result.fullscreen.box.height - result.fullscreen.viewport.height) <= 1, 'fullscreen height');
      assertRect(result.fullscreen.video, result.fullscreen.box, 'video fills fullscreen container');
    }
  }
  console.log(JSON.stringify(result, null, 2));
  console.log(observe ? 'OBSERVED: baseline only' :
    `PASS: text scales; fixed media and viewport stay consistent${fullscreen ? '; fullscreen geometry verified' : ''}`);
} finally {
  if (targetId) await call('Target.closeTarget', { targetId });
  socket.close();
}
