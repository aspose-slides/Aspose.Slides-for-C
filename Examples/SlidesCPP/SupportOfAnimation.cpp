#include <DOM/Slide.h>
#include <DOM/SlideCollection.h>
#include <DOM/Presentation.h>
#include <DOM/IAutoShape.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/ITextFrame.h>
#include <DOM/Shape.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;


void SupportOfAnimation() {
	
	//// ExStart:SupportOfAnimation

	////Instantiate a presentation	
	//SharedPtr<Presentation> pres = MakeObject<Presentation>();


	////Get first slide
	//SharedPtr<ISlide> slideOne = pres->get_Slides()->idx_get(1);


	////Add a rectangle shape
	//SharedPtr<IAutoShape>  rectangleShape = slideOne->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 50, 500, 250);

	////Add a Text Frame
	//rectangleShape->AddTextFrame(u"Animated Text");
	//
	////Set shape to fit according to text
	//rectangleShape->get_TextFrame()->set_FitShapeToText(true);
	//// ExEnd:SupportOfAnimation

}