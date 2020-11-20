#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void CheckPasswordExample()
{
    //ExStart:CheckPasswordExample
    //Path for source presentation
    String pptFile = Path::Combine(GetDataPath(), u"open_pass1.ppt");

    // Check the Password via IPresentationInfo Interface
    SharedPtr<IPresentationInfo> presentationInfo = PresentationFactory::get_Instance()->GetPresentationInfo(pptFile);
    bool isPasswordCorrect = presentationInfo->CheckPassword(u"my_password");
    Console::WriteLine(String(u"The password \"my_password\" for the presentation is ") + isPasswordCorrect);

    isPasswordCorrect = presentationInfo->CheckPassword(u"pass1");
    Console::WriteLine(String(u"The password \"pass1\" for the presentation is ") + isPasswordCorrect);
    //ExEnd:CheckPasswordExample
}
