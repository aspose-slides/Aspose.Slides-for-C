#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ImportHtmlSlideExample()
{
    const String htmlFileName = Path::Combine(GetDataPath(), u"TestHtml.html");
    const String outPresName = Path::Combine(GetOutPath(), u"OutputConvertedHtml.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>();
    SharedPtr<Stream> inputStream = MakeObject<FileStream>(htmlFileName, FileMode::Open);
    pres->get_Slides()->InsertFromHtml(0, inputStream, true);

    // Save the presentation
    pres->Save(outPresName, SaveFormat::Pptx);
}
