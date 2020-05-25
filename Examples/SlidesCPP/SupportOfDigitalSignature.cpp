#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SupportOfDigitalSignature()
{
    //ExStart:SupportOfDigitalSignature
    SharedPtr<DigitalSignature> signature = System::MakeObject<DigitalSignature>(GetDataPath() + u"testsignature1.pfx", u"testpass1");
    signature->set_Comments(u"Aspose.Slides digital signing test.");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    pres->get_DigitalSignatures()->Add(signature);

    pres->Save(GetOutPath() + u"SomePresentationSigned.pptx", SaveFormat::Pptx);
    //ExEnd:SupportOfDigitalSignature
}
