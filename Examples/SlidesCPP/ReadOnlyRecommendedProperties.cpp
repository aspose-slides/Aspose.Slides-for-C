#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ReadOnlyRecommendedProperties()
{
    //ExStart:ReadOnlyRecommendedProperties
    String outPptxPath = Path::Combine(GetOutPath(), u"ReadOnlyRecommended.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    pres->get_ProtectionManager()->set_ReadOnlyRecommended(true);
    pres->Save(outPptxPath, SaveFormat::Pptx);
    //ExEnd:ReadOnlyRecommendedProperties
}
