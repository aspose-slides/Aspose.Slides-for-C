#include "stdafx.h"
#include <DOM/InterruptionToken.h>
#include <DOM/InterruptionTokenSource.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void SettingInterruptionToken()
{
    //ExStart:SettingInterruptionToken

    System::SharedPtr<InterruptionTokenSource> tokenSource = System::MakeObject<InterruptionTokenSource>();
    std::function<void()> _local_func_0 = [&tokenSource]()
    {
        const System::String templatePath = u"../templates/AccessSlides.pptx";
        const System::String outPath = u"../out/SettingInterruptionToken_out.ppt";

        System::SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
        loadOptions->set_InterruptionToken(tokenSource->get_Token());
        System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath, loadOptions);
        System::SharedPtr<ISlide> slide = pres->get_Slide(0);
        slide->GetImage(System::Drawing::Size(960, 720));
        pres->Save(outPath, SaveFormat::Ppt);
    };

    //	System::SharedPtr<System::Threading::Thread> thread = System::MakeObject<System::Threading::Thread>(static_cast<System::Threading::ThreadStart>(_local_func_0));
    //	thread->Start();

    //	System::Threading::Thread::Sleep(5000); // some work

    //	tokenSource->Interrupt();


    //ExEnd:SettingInterruptionToken
}
