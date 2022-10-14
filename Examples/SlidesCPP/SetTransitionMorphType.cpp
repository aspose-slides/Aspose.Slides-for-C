#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SlideShow;
using namespace System;

void SetTransitionMorphType()
{
	//ExStart:SetTransitionMorphType
	const String inputPath = u"../templates/presentation.pptx";
	const String outPath = u"../out/presentation-out.pptx";
	auto presentation = System::MakeObject<Presentation>(inputPath);

	presentation->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_Type(TransitionType::Morph);

	auto morphTransition = System::ExplicitCast<IMorphTransition>(presentation->get_Slides()->idx_get(0)->get_SlideShowTransition()->get_Value());
	morphTransition->set_MorphType(TransitionMorphType::ByWord);

	presentation->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:SetTransitionMorphType
}
