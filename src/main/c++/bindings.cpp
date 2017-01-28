#include <nan.h>
#include "winlock.h"

void IsLocked(const Nan::FunctionCallbackInfo<v8::Value>& info){
    info.GetReturnValue().Set(Nan::New(isWorkstationLocked()));
}

void Lock(const Nan::FunctionCallbackInfo<v8::Value>& info){
    lockWorkstation();
}

void Init(v8::Local<v8::Object> exports){
    exports->Set(Nan::New("isLocked").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(IsLocked)->GetFunction());
    exports->Set(Nan::New("lock").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Lock)->GetFunction());
}

NODE_MODULE(winlock, Init)