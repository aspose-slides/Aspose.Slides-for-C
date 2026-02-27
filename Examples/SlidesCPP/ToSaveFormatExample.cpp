#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace Util;

using namespace System;
using namespace IO;

void ToSaveFormatExample()
{
    const String presentationPath = Path::Combine(GetDataPath(), u"Presentation.pptm");

    SharedPtr<Presentation> sourcePresentation = MakeObject<Presentation>(presentationPath);

    // Modify the presentation as you need
    sourcePresentation->get_Slides()->AddClone(sourcePresentation->get_Slide(0));

    // Save the presentation to the stream in its original format
    auto stream = MakeObject<MemoryStream>();
    sourcePresentation->Save(stream, SlideUtil::ToSaveFormat(sourcePresentation->get_SourceFormat()));
}
