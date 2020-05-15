#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Animation;
using namespace System;

void GetEffectsByTextParagraph()
{
	// ExStart:GetEffectsByTextParagraph

	// The path to the documents directory.
	const String templatePath = u"../templates/Para Effects.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<ISequence> sequence = slide->get_Timeline()->get_MainSequence();

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Accessing second shape from slide.
	SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(1);
	SharedPtr<AutoShape> ashp = DynamicCast<AutoShape>(shape);
	
	for (int i = 0; i < ashp->get_TextFrame()->get_Paragraphs()->get_Count(); i++)
	{
		SharedPtr<IParagraph> para = ashp->get_TextFrame()->get_Paragraphs()->idx_get(i);

		ArrayPtr<SharedPtr<IEffect>> effects = sequence->GetEffectsByParagraph(para);

		if (effects->get_Count() > 0)
		{
			Console::WriteLine(u"Paragraph = " + para->get_Text() + u" has "+ effects[0]->GetType() + u" effect.");
		}
	}
	
	//ExEnd:GetEffectsByTextParagraph
}


