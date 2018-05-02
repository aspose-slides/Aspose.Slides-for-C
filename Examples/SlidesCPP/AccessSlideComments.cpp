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

void AccessSlideComments()
{
	//ExStart:AccessSlideComments

	// The path to the documents directory.
	const String templatePath = u"../templates/Comments1.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Accessing comments collection
	const int commentsCount = pres->get_CommentAuthors()->get_Count();

	for (int i = 0; i < commentsCount; i++)
	{
		auto author = pres->get_CommentAuthors()->idx_get(i);
		//std::cout << "Comments from: " << author->get_Name() << std::endl;
		System::Console::WriteLine(u"Comments from: " + author->get_Name());
		for (int j = 0; j < author->get_Comments()->get_Count(); j++)
		{
			auto comment = author->get_Comments()->idx_get(j);
			System::Console::WriteLine(u"Comment: " + comment->get_Text());

		}
	}
	//ExEnd:AccessSlideComments
}
