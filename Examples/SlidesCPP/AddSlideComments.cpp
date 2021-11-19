#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;
using System::Drawing::PointF;

void AddSlideComments()
{
	//ExStart:AddSlideComments
	
	// The path to the output file.
	const String outPath = Path::Combine(GetOutPath(), u"AddComments.pptx");

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
	SharedPtr<ILayoutSlide> layout = pres->get_LayoutSlides()->idx_get(0);

	pres->get_Slides()->AddEmptySlide(layout);

	// Adding Author
	SharedPtr<ICommentAuthor> author = pres->get_CommentAuthors()->AddAuthor(u"Mudassir", u"MF");

	// Position of comments
	PointF point = PointF(0.2f, 0.2f);

	// Adding slide comment for an author on slide 1
	author->get_Comments()->AddComment(u"Hello Mudassir, this is slide comment", pres->get_Slides()->idx_get(0), point, DateTime::get_Now());

	// Adding slide comment for an author on slide 1
	author->get_Comments()->AddComment(u"Hello Mudassir, this is second slide comment", pres->get_Slides()->idx_get(1), point, DateTime::get_Now());

	// Accessing ISlide 1
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddSlideComments
}
