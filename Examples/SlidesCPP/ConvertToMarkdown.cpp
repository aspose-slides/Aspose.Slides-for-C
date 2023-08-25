#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;

void ConvertToMarkdown()
{
    //ExStart:ConvertToMarkdown

    // Path to source presentation
    const String presentationName = u"../templates/PresentationDemo.pptx";
    // Path and folder name for saving markdown data
    const String outPath = u"../out";

    SharedPtr<Presentation> pres = MakeObject<Presentation>(presentationName);

    // Create Markdown creation options
    SharedPtr<MarkdownSaveOptions> mdOptions = MakeObject<MarkdownSaveOptions>();
    // Set parameter for render all items (items that are grouped will be rendered together).
    mdOptions->set_ExportType(MarkdownExportType::Visual);
    // Set folder name for saving images
    mdOptions->set_ImagesSaveFolderName(u"md-images");
    // Set path for folder images
    mdOptions->set_BasePath(outPath);

    // Save presentation in Markdown format
    pres->Save(Path::Combine(outPath, u"pres.md"), SaveFormat::Md, mdOptions);

    //ExEnd:ConvertToMarkdown
}
