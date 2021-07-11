#include <nan.h>
#include "winlock.h"

void IsLocked(const Nan::FunctionCallbackInfo<v8::Value>& info){
    info.GetReturnValue().Set(Nan::New(isWorkstationLocked()));
}

void Lock(const Nan::FunctionCallbackInfo<v8::Value>& info){
    lockWorkstation();
}

void Init(v8::Local<v8::Object> exports){
    v8::Local<v8::Context> context = exports->CreationContext();
    exports->Set(context, Nan::New("isLocked").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(IsLocked)->GetFunction(Nan::GetCurrentContext()).ToLocalChecked());
    exports->Set(context, Nan::New("lock").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Lock)->GetFunction(Nan::GetCurrentContext()).ToLocalChecked());
}

NODE_MODULE(winlock, Init)