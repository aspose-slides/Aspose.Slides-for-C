#include "stdafx.h"
#include "SlidesExamples.h"

using namespace System;
using namespace IO;
using namespace Aspose::Slides;
using namespace Export;

void ConvertToBlackWhiteTiff()
{
    //ExStart:ConvertToBlackWhiteTiff
    const String presentationName = Path::Combine(GetDataPath(), u"SimpleAnimations.pptx");
    const String outFilePath = Path::Combine(GetOutPath(), u"BlackWhite_out.tiff");

    SharedPtr<Presentation> presentation = MakeObject<Presentation>(presentationName);

    // Instantiate the TiffOptions class
    SharedPtr<TiffOptions> options = MakeObject<TiffOptions>();
    // Set compressio type
    options->set_CompressionType(TiffCompressionTypes::CCITT4);
    // Set convertion mode
    options->set_BwConversionMode(BlackWhiteConversionMode::Dithering);

    // Save output file
    presentation->Save(outFilePath, MakeArray<int32_t>({ 2 }), SaveFormat::Tiff, options);
    //ExEnd:ConvertToBlackWhiteTiff
}
