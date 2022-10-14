#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void Hidingshapes()
{
	// ExStart:Hidingshapes

	// The path to the documents directory.
	const String outPath = u"../out/Hidingshapes_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Now create effect "PathFootball" for existing shape from scratch.
	SharedPtr<IAutoShape> autoShape1 = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 50, 40, 150, 50);
	SharedPtr<IAutoShape> autoShape2 = slide->get_Shapes()->AddAutoShape(ShapeType::Moon, 160, 40, 150, 50);

	String alttext = u"User Defined";

	int iCount = slide->get_Shapes()->get_Count();
	for (int i = 0; i < iCount; i++)
	{
		// Accessing the added shape
		SharedPtr<AutoShape>  ashape = ExplicitCast<AutoShape>(slide->get_Shapes()->idx_get(i));

		if (String::Compare(ashape->get_AlternativeText(), alttext, StringComparison::Ordinal) == 0)
		{
			ashape->set_Hidden(true);
		}
	}

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:Hidingshapes
}
