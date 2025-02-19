#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void GetPresentationRowTextExample()
{
    const String inputPath = Path::Combine(GetDataPath(), u"PresentationText.pptx");

    SharedPtr<IPresentationText> presentationText = PresentationFactory::get_Instance()->GetPresentationText(inputPath, TextExtractionArrangingMode::Unarranged);

    Console::WriteLine(u"Comments for Slide 1 : {0}", presentationText->get_SlidesText()->idx_get(0)->get_CommentsText());
    Console::WriteLine(u"Text for Slide 1 : {0}", presentationText->get_SlidesText()->idx_get(0)->get_Text());
    Console::WriteLine(u"Notes for Slide 2 : {0}", presentationText->get_SlidesText()->idx_get(0)->get_NotesText());
}
