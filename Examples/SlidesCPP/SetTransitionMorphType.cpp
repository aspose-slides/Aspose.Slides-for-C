#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/SlideShowTransition/TransitionType.h>
#include <DOM/SlideShowTransition/TransitionMorphType.h>
#include <DOM/SlideShowTransition/IMorphTransition.h>
#include <DOM/ISlideShowTransition.h>
#include <DOM/ShapeType.h>
#include <DOM/AutoShape.h>

#include <DOM/ITextFrame.h>
#include <system/string.h>
#include <system/IO/file.h>


#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SlideShow;

using namespace System;

void SetTransitionMorphType()
{
	//ExStart:SetTransitionMorphType
	const String inputPath = u"../templates/presentation.pptx";
	const String outPath = u"../out/presentation-out.pptx";
	auto presentation = System::MakeObject<Presentation>(u"presentation.pptx");

	presentation->get_Slides()->idx_get(0)->get_SlideShowTransition()->set_Type(Aspose::Slides::SlideShow::TransitionType::Morph);

	auto morphTransition = System::DynamicCast<Aspose::Slides::SlideShow::IMorphTransition>(presentation->get_Slides()->idx_get(0)->get_SlideShowTransition()->get_Value());
	morphTransition->set_MorphType(Aspose::Slides::SlideShow::TransitionMorphType::ByWord);

	presentation->Save(u"presentation-out.pptx", Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SetTransitionMorphType
}
