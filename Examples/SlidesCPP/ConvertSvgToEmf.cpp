#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void ConvertSvgToEmf()
{
    //ExStart:ConvertSvgToEmf

    // The path to the documents directory.
    const String inputPath = Path::Combine(GetDataPath(), u"content.svg");
    // Output path
    const String resultPath = Path::Combine(GetOutPath(), u"SvgAsEmf.emf");

    // Creates the new SVG image
    SharedPtr<ISvgImage> svgImage = MakeObject<SvgImage>(File::ReadAllText(inputPath));

    // Saves the SVG image as a metafile
    auto fileStream = File::Create(resultPath);
    svgImage->WriteAsEmf(fileStream);

    //ExEnd:ConvertSvgToEmf
}
