#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void ConvertToFodp()
{
    //ExStart:ConvertToFodp
    const String dataDir = GetDataPath();
    const String outFodpPath = Path::Combine(GetOutPath(), u"FodpFormatConvertion.fodp");
    const String outPptxPath = Path::Combine(GetOutPath(), u"FodpFormatConvertion.pptx");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(dataDir + u"Example.fodp");
    presentation->Save(outPptxPath, SaveFormat::Pptx);

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(outPptxPath);
    pres->Save(outFodpPath, SaveFormat::Fodp);
    //ExEnd:ConvertToFodp
}
