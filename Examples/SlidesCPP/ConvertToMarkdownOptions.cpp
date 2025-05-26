#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ConvertToMarkdownOptions()
{
    // Paths
    const String presentationPath = Path::Combine(GetDataPath(), u"PresentationDemo.pptx");
    const String mdOutPath = Path::Combine(GetOutPath(), u"pres-out.md");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationPath);

    SharedPtr<MarkdownSaveOptions> options = MakeObject<MarkdownSaveOptions>();
    options->set_RemoveEmptyLines(true);
    options->set_HandleRepeatedSpaces(HandleRepeatedSpaces::AlternateSpacesToNbsp);
    options->set_SlideNumberFormat(u"## Slide {0} -");
    options->set_ShowSlideNumber(true);
    options->set_ExportType(MarkdownExportType::TextOnly);
    options->set_Flavor(Flavor::Default);

    // Save presentation in Markdown format
    pres->Save(mdOutPath, SaveFormat::Md, options);
}
