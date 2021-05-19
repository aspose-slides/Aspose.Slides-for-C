#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void RootDirectoryClsId()
{
    //ExStart:RootDirectoryClsId
    String resultPath = Path::Combine(GetOutPath(), u"pres.ppt");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    SharedPtr<PptOptions> pptOptions = System::MakeObject<PptOptions>();
    // set CLSID to 'Microsoft Powerpoint.Show.8'
    pptOptions->set_RootDirectoryClsid(Guid(u"64818D10-4F9B-11CF-86EA-00AA00B929E8"));

    pres->Save(resultPath, SaveFormat::Ppt, pptOptions);
    //ExEnd:RootDirectoryClsId
}
