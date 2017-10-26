#include "mymodule.h"

Nan::Persistent<v8::Function> MyModule::constructor;

MyModule::MyModule() :
        astring(" ")
{
}

MyModule::~MyModule() {
}

void MyModule::Init(v8::Local<v8::Object> exports) {
        v8::Isolate* isolate = exports->GetIsolate();

// Prepare constructor template
        v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
        tpl->SetClassName(v8::String::NewFromUtf8(isolate, "MyModule"));
        tpl->InstanceTemplate()->SetInternalFieldCount(1);

        // Prototype
        Nan::SetPrototypeMethod(tpl, "Get", GetValue);
        Nan::SetPrototypeMethod(tpl, "Set", SetString);


        constructor.Reset(tpl->GetFunction());
        exports->Set(v8::String::NewFromUtf8(isolate, "MyModule"),
                     tpl->GetFunction());
}

void MyModule::New(const v8::FunctionCallbackInfo<v8::Value>& info) {
        if (info.IsConstructCall()) {
                // Invoked as constructor: `new MyModule()`
                MyModule* obj = new MyModule();
                obj->Wrap(info.This());
                info.GetReturnValue().Set(info.This());
        } else {
                // Invoked as plain function `ACreator(...)`, turn into construct call.
                const int argc = 1;
                v8::Local<v8::Value> argv[argc] = { info[0] };
                v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
                info.GetReturnValue().Set(Nan::NewInstance(cons,argc, argv).ToLocalChecked());
        }
}


void MyModule::SetString(const Nan::FunctionCallbackInfo<v8::Value>& info) {
        v8::Isolate *isolate = info.GetIsolate();
        MyModule* obj = ObjectWrap::Unwrap<MyModule>(info.Holder());

        if ( info.Length()!=1 ) {
                isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Set is expecting 1 parameters")));
                return;
        }else if ( !info[0]->IsString() ) {
                isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Set is expecting a string as parameter")));
                return;
        }
        //check which is the first empty spot to save the string
        v8::String::Utf8Value s(info[0]);
        std::string str(*s);
        obj->astring = str;
        info.GetReturnValue().Set(v8::String::NewFromUtf8(isolate,str.c_str()));
}


void MyModule::GetValue(const Nan::FunctionCallbackInfo<v8::Value>& info) {
        v8::Isolate *isolate = info.GetIsolate();

        MyModule* obj = ObjectWrap::Unwrap<MyModule>(info.Holder());

        if ( info.Length()!=0 ) {
                isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Get is expectin zero parameters")));
                return;
        }

        std::string str = obj->astring.c_str();

        info.GetReturnValue().Set(v8::String::NewFromUtf8(isolate,str.c_str()));
}
