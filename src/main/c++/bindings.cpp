#include <nan.h>
#include "winlock.h"

void IsLocked(const Nan::FunctionCallbackInfo<v8::Value>& info){
    info.GetReturnValue().Set(Nan::New(isWorkstationLocked()));
}

void Lock(const Nan::FunctionCallbackInfo<v8::Value>& info){
    lockWorkstation();
}

NAN_MODULE_INIT(Init) {
    Nan::Set(target, Nan::New("isLocked").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(IsLocked)->GetFunction(Nan::GetCurrentContext()).ToLocalChecked());
    Nan::Set(target, Nan::New("lock").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Lock)->GetFunction(Nan::GetCurrentContext()).ToLocalChecked());
}

NODE_MODULE(winlock, Init)