#include "stdafx.h"
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
		Console::WriteLine(u"Comments from: " + author->get_Name());
		for (int j = 0; j < author->get_Comments()->get_Count(); j++)
		{
			auto comment = author->get_Comments()->idx_get(j);
			Console::WriteLine(u"Comment: " + comment->get_Text());
		}
	}
	//ExEnd:AccessSlideComments
}
