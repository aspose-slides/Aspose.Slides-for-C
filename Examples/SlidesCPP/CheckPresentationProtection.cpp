#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void CheckPresentationProtection()
{
    //ExStart:CheckPresentationProtection
    //Path for source presentation
    String pptxFile = Path::Combine(GetDataPath(), u"modify_pass2.pptx");
    String pptFile = Path::Combine(GetDataPath(), u"open_pass1.ppt");

    // Check the Write Protection Password via IPresentationInfo Interface
    SharedPtr<IPresentationInfo> presentationInfo = PresentationFactory::get_Instance()->GetPresentationInfo(pptxFile);
    bool isWriteProtectedByPassword = presentationInfo->get_IsWriteProtected() == NullableBool::True && presentationInfo->CheckWriteProtection(u"pass2");
    Console::WriteLine(String(u"Is presentation write protected by password = ") + isWriteProtectedByPassword);

    // Check the Write Protection Password via IProtectionManager Interface
    auto presentation = System::MakeObject<Presentation>(pptxFile);

    bool isWriteProtected = presentation->get_ProtectionManager()->CheckWriteProtection(u"pass2");
    Console::WriteLine(String(u"Is presentation write protected = ") + isWriteProtected);

    // Check Presentation Open Protection via IPresentationInfo Interface
    presentationInfo = PresentationFactory::get_Instance()->GetPresentationInfo(pptFile);
    if (presentationInfo->get_IsPasswordProtected())
    {
        Console::WriteLine(String(u"The presentation '") + pptxFile + u"' is protected by password to open.");
    }
    //ExEnd:CheckPresentationProtection
}
