#include <napi.h>
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <Util/License.h>

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void convert_to_pdf(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    
    if (info.Length() < 2)
    {
        throw Napi::Error::New(env, "Wrong number of arguments");
    }
    
    String presentation_name = String::FromAscii(info[0].As<Napi::String>().Utf8Value());
    String pdf_name = String::FromAscii(info[1].As<Napi::String>().Utf8Value());
        
    try
    {
        SharedPtr<Presentation> pres = MakeObject<Presentation>(presentation_name);
        pres->Save(pdf_name, SaveFormat::Pdf);
    }
    catch (Exception ex)
    {
        throw Napi::Error::New(env, ex.ToString().ToAsciiString().c_str());
    }
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "convert_to_pdf"), Napi::Function::New(env, convert_to_pdf));
    
    return exports;
}

NODE_API_MODULE(AsposeSlidesCppNodejsAddon, Init)