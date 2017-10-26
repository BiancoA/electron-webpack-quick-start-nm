#ifndef MYCREATOR_H
#define MYCREATOR_H

#include <nan.h>


class MyModule : public Nan::ObjectWrap {
public:
static void Init(v8::Local<v8::Object> exports);

private:
explicit MyModule();
~MyModule();

static void New(const v8::FunctionCallbackInfo<v8::Value>& info);
static void GetValue(const Nan::FunctionCallbackInfo<v8::Value>& info);
static void SetString(const Nan::FunctionCallbackInfo<v8::Value>& info);

static Nan::Persistent<v8::Function> constructor;

std::string astring;

};

#endif
