#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/SlideShowTransition/TransitionType.h>
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

void SupportOfMorphTransition()
{
	//ExStart:SupportOfMorphTransition

	const String outPath = u"../out/presentation-out.pptx";
	auto presentation = System::MakeObject<Presentation>();
	auto autoshape = System::DynamicCast<Aspose::Slides::AutoShape>(presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(Aspose::Slides::ShapeType::Rectangle, 100, 100, 400, 100));
	
	
	autoshape->get_TextFrame()->set_Text(u"Test text");
	presentation->get_Slides()->AddClone(presentation->get_Slides()->idx_get(0));
	
	auto x = presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->get_X();
	auto y = presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->get_Y();
	auto width = presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->get_Width();
	auto height = presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->get_Height();

	presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->set_X(x + 100);
	presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->set_Y(y + 50);
	presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->set_Width(width + 200);
	presentation->get_Slides()->idx_get(1)->get_Shapes()->idx_get(0)->set_Height(height + 10);

	presentation->get_Slides()->idx_get(1)->get_SlideShowTransition()->set_Type(Aspose::Slides::SlideShow::TransitionType::Morph);

	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SupportOfMorphTransition
}
