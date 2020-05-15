#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System;

void CloneSlideIntoSpecifiedSection()
{
    //ExStart:CloneSlideIntoSpecifiedSection

	const String outPath = u"../out/CloneSlideIntoSpecifiedSection.pptx";
	auto presentation = MakeObject<Presentation>();

	presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 200.0f, 50.0f, 300.0f, 100.0f);

	presentation->get_Sections()->AddSection(u"Section 1", presentation->get_Slides()->idx_get(0));

	auto section2 = presentation->get_Sections()->AppendEmptySection(u"Section 2");

	presentation->get_Slides()->AddClone(presentation->get_Slides()->idx_get(0), section2);

	presentation->Save(outPath, SaveFormat::Pptx);

    //ExEnd:CloneSlideIntoSpecifiedSection
}
