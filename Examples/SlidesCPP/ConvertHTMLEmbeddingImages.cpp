#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;

void ConvertHTMLEmbeddingImages()
{
    //ExStart:ConvertHTMLEmbeddingImages

    // Path to source presentation
    const String presentationName = u"../templates/PresentationDemo.pptx";
    // Path to HTML document
    const String outFilePath = u"../out/HTMLConvertion";

    const String outPath = u"../out";

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationName);

    SharedPtr<Html5Options> options = System::MakeObject<Html5Options>();
    options->set_EmbedImages(false);
    options->set_OutputPath(outPath);

    // Create directory for output HTML document
    if (!Directory::Exists(outFilePath))
    {
        Directory::CreateDirectory_(outFilePath);
    }

    // Save presentation in HTML5 format.
    pres->Save(Path::Combine(outFilePath, u"pres.html"), SaveFormat::Html5, options);

    //ExEnd:ConvertHTMLEmbeddingImages
}
