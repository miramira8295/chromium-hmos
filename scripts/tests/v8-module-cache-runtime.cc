// Device-independent V8 module-cache acceptance/rejection probe.
// This does not exercise Blink's metadata handler or the response handoff.
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include "include/libplatform/libplatform.h"
#include "include/v8.h"

namespace {
struct Engine {
  std::unique_ptr<v8::ArrayBuffer::Allocator> allocator{
      v8::ArrayBuffer::Allocator::NewDefaultAllocator()};
  v8::Isolate* isolate;
  Engine() {
    v8::Isolate::CreateParams params;
    params.array_buffer_allocator = allocator.get();
    isolate = v8::Isolate::New(params);
  }
  ~Engine() { isolate->Dispose(); }
};

v8::Local<v8::String> Text(v8::Isolate* isolate, const std::string& value) {
  return v8::String::NewFromUtf8(isolate, value.c_str()).ToLocalChecked();
}

v8::ScriptOrigin Origin(v8::Isolate* isolate) {
  return v8::ScriptOrigin(Text(isolate, "https://fixture.invalid/module.js"),
                          0, 0, true, -1, v8::Local<v8::Value>(), false, false,
                          true);
}

std::string Code(int result) {
  return "globalThis.observed = " + std::to_string(result) +
         "; export const result = " + std::to_string(result) + "; // " +
         std::string(2000, 'x');
}

std::vector<uint8_t> Produce() {
  Engine engine;
  v8::Isolate::Scope isolate_scope(engine.isolate);
  v8::HandleScope handles(engine.isolate);
  auto context = v8::Context::New(engine.isolate);
  v8::Context::Scope context_scope(context);
  v8::ScriptCompiler::Source source(Text(engine.isolate, Code(42)),
                                    Origin(engine.isolate));
  v8::Local<v8::Module> module;
  if (!v8::ScriptCompiler::CompileModule(engine.isolate, &source).ToLocal(&module))
    return {};
  std::unique_ptr<v8::ScriptCompiler::CachedData> cache(
      v8::ScriptCompiler::CreateCodeCache(module->GetUnboundModuleScript()));
  if (!cache || cache->length <= 0)
    return {};
  // V8 owns the input allocation; take a copy before disposing its isolate.
  return {cache->data, cache->data + cache->length};
}

bool Check(const char* name, int mode) {
  auto bytes = Produce();
  if (bytes.size() < 8) {
    std::printf("{\"case\":\"%s\",\"passed\":false,\"error\":\"no payload\"}\n", name);
    return false;
  }
  if (mode == 1)
    bytes[0] ^= 0xff;
  if (mode == 2)
    bytes.resize(1);
  const int expected = mode == 3 ? 43 : 42;
  std::string code = Code(expected);
  if (mode == 3)
    code += "\n// updated source length\n";
  Engine engine;
  v8::Isolate::Scope isolate_scope(engine.isolate);
  v8::HandleScope handles(engine.isolate);
  auto context = v8::Context::New(engine.isolate);
  v8::Context::Scope context_scope(context);
  v8::TryCatch catcher(engine.isolate);
  v8::ScriptCompiler::Source source(
      Text(engine.isolate, code), Origin(engine.isolate),
      new v8::ScriptCompiler::CachedData(bytes.data(), static_cast<int>(bytes.size()),
                                        v8::ScriptCompiler::CachedData::BufferNotOwned));
  v8::Local<v8::Module> module;
  const bool compiled = v8::ScriptCompiler::CompileModule(
      engine.isolate, &source, v8::ScriptCompiler::kConsumeCodeCache).ToLocal(&module);
  const bool rejected = source.GetCachedData()->rejected;
  bool executed = false;
  int value = -1, observed = -1;
  if (compiled && module->InstantiateModule(context,
          [](v8::Local<v8::Context>, v8::Local<v8::String>,
             v8::Local<v8::FixedArray>, v8::Local<v8::Module>)
              -> v8::MaybeLocal<v8::Module> { return {}; }).FromMaybe(false)) {
    v8::Local<v8::Value> evaluation, result, side_effect;
    if (module->Evaluate(context).ToLocal(&evaluation) && evaluation->IsPromise() &&
        evaluation.As<v8::Promise>()->State() == v8::Promise::kFulfilled &&
        module->GetModuleNamespace().As<v8::Object>()
            ->Get(context, Text(engine.isolate, "result")).ToLocal(&result) &&
        context->Global()->Get(context, Text(engine.isolate, "observed"))
            .ToLocal(&side_effect)) {
      value = result->Int32Value(context).FromMaybe(-1);
      observed = side_effect->Int32Value(context).FromMaybe(-1);
      executed = true;
    }
  }
  const bool passed = compiled && !catcher.HasCaught() && executed &&
      rejected == (mode != 0) && value == expected && observed == expected;
  std::printf("{\"case\":\"%s\",\"passed\":%s,\"cacheRejected\":%s,"
              "\"compiled\":%s,\"executed\":%s,\"export\":%d,\"sideEffect\":%d}\n",
              name, passed ? "true" : "false", rejected ? "true" : "false",
              compiled ? "true" : "false", executed ? "true" : "false", value, observed);
  return passed;
}
}  // namespace

int main(int argc, char** argv) {
  if (!v8::V8::InitializeICUDefaultLocation(argv[0], argc > 1 ? argv[1] : nullptr))
    return 3;
  auto platform = v8::platform::NewDefaultPlatform();
  v8::V8::InitializePlatform(platform.get());
  if (!v8::V8::Initialize())
    return 4;
  std::printf("{\"v8Version\":\"%s\"}\n", v8::V8::GetVersion());
  bool passed = true;
  passed &= Check("valid", 0);
  passed &= Check("corrupt-header", 1);
  passed &= Check("truncated-payload", 2);
  passed &= Check("changed-source", 3);
  v8::V8::Dispose();
  v8::V8::DisposePlatform();
  return passed ? 0 : 2;
}
