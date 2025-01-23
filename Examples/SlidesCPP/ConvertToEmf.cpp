#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void ConvertToEmf()
{
    //ExStart:ConvertToEmf

    // The path to the documents directory.
    const String pptxPath = Path::Combine(GetDataPath(), u"HelloWorld.pptx");
    // Output path
    const String resultPath = Path::Combine(GetOutPath(), u"Result.emf");

    // Instantiate a Presentation object that represents a presentation file
    SharedPtr<Presentation> presentation = MakeObject<Presentation>(pptxPath);
    auto fileStream = File::Create(resultPath);
    // Saves the first slide as a metafille
    presentation->get_Slide(0)->WriteAsEmf(fileStream);

    //ExEnd:ConvertToEmf
}
