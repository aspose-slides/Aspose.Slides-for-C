#include <iostream>
#include <system/console.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/ICommentAuthorCollection.h>
#include <DOM/ICommentCollection.h>
#include <DOM/IComment.h>
#include <DOM/ICommentAuthor.h>


//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;

using namespace System;

void AddSlideComments()
{
	//ExStart:AddSlideComments
	
	//Presentation path
	const String outPath = L"../out/AddComments.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>();
	SharedPtr<ILayoutSlide>layout = pres->get_LayoutSlides()->idx_get(0);

	pres->get_Slides()->AddEmptySlide(layout);

	// Adding Author
	SharedPtr<ICommentAuthor> author = pres->get_CommentAuthors()->AddAuthor(L"Mudassir", L"MF");

	// Position of comments
	System::Drawing::PointF point = System::Drawing::PointF(0.2f, 0.2f);


	// Adding slide comment for an author on slide 1
	author->get_Comments()->AddComment(L"Hello Mudassir, this is slide comment", pres->get_Slides()->idx_get(0), point, System::DateTime::get_Now());

	// Adding slide comment for an author on slide 1
	author->get_Comments()->AddComment(L"Hello Mudassir, this is second slide comment", pres->get_Slides()->idx_get(1), point, DateTime::get_Now());

	// Accessing ISlide 1
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddSlideComments
}