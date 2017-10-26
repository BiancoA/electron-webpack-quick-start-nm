#include <nan.h>
#include "mymodule.h"

void InitAll(v8::Local<v8::Object> exports) {
  MyModule::Init(exports);
}

NODE_MODULE(mymoduleND, InitAll)
