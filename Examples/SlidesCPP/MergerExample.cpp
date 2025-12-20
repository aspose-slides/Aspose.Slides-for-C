#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void MergerExample()
{
    //ExStart:MergerExample

    const String pptxFileName1 = Path::Combine(GetDataPath(), u"ForEachPortion.pptx");
    const String pptxFileName2 = Path::Combine(GetDataPath(), u"ConvertExample.pptx");
    const String pptxFileName3 = Path::Combine(GetDataPath(), u"MultipleMaster.pptx");
    const String outPptxFile = Path::Combine(GetOutPath(), u"Merged-out.pptx");

    LowCode::Merger::Process(MakeArray<String>({pptxFileName1, pptxFileName2, pptxFileName3}), outPptxFile);

    //ExEnd:MergerExample
}
