#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void CompressionLevelExample()
{
    // The path to output files
    const String outFileLevel1 = Path::Combine(GetOutPath(), u"PresentationCompressionLevel1.pptx");
    const String outFileLevel9 = Path::Combine(GetOutPath(), u"PresentationCompressionLevel9.pptx");

    auto pres = MakeObject<Presentation>();

    // Fastest compression with the lowest compression ratio.
    SharedPtr<PptxOptions> pptxOptions = MakeObject<PptxOptions>();
    pptxOptions->set_CompressionLevel(CompressionLevel::Level1);
    pres->Save(outFileLevel1, SaveFormat::Pptx, pptxOptions);

    // Maximum compression. Produces the smallest file size with the slowest processing speed.
    pptxOptions->set_CompressionLevel(CompressionLevel::Level9);
    pres->Save(outFileLevel9, SaveFormat::Pptx, pptxOptions);
}
