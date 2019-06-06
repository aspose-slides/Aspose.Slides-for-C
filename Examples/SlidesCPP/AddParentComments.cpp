#include "SlidesExamples.h"
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

using namespace Aspose::Slides;

using namespace System;

void AddParentComments()
{
	//ExStart:AddParentComments

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	// Add comment
	System::SharedPtr<ICommentAuthor> author1 = pres->get_CommentAuthors()->AddAuthor(u"Author_1", u"A.A.");
	System::SharedPtr<IComment> comment1 = author1->get_Comments()->AddComment(u"comment1", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());

	// Add reply for comment1
	System::SharedPtr<ICommentAuthor> author2 = pres->get_CommentAuthors()->AddAuthor(u"Autror_2", u"B.B.");
	System::SharedPtr<IComment> reply1 = author2->get_Comments()->AddComment(u"reply 1 for comment 1", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());
	reply1->set_ParentComment(comment1);

	// Add reply for comment1
	System::SharedPtr<IComment> reply2 = author2->get_Comments()->AddComment(u"reply 2 for comment 1", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());
	reply2->set_ParentComment(comment1);

	// Add reply to reply
	System::SharedPtr<IComment> subReply = author1->get_Comments()->AddComment(u"subreply 3 for reply 2", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());
	subReply->set_ParentComment(reply2);

	System::SharedPtr<IComment> comment2 = author2->get_Comments()->AddComment(u"comment 2", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());
	System::SharedPtr<IComment> comment3 = author2->get_Comments()->AddComment(u"comment 3", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());

	System::SharedPtr<IComment> reply3 = author1->get_Comments()->AddComment(u"reply 4 for comment 3", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), System::DateTime::get_Now());
	reply3->set_ParentComment(comment3);

	// Display hierarchy on console
	System::SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
	auto comments = slide->GetSlideComments(nullptr);
	for (int32_t i = 0; i < comments->get_Length(); i++)
	{
		System::SharedPtr<IComment> comment = comments[i];
		while (comment->get_ParentComment() != nullptr)
		{
			System::Console::Write(u"\t");
			comment = comment->get_ParentComment();
		}

		System::Console::Write(u"{0} : {1}", System::ObjectExt::Box<System::String>(comments[i]->get_Author()->get_Name()), System::ObjectExt::Box<System::String>(comments[i]->get_Text()));
		System::Console::WriteLine();
	}
	pres->Save(u"../out/parent_comment.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
	// Remove comment1 and all its replies
	comment1->Remove();

	pres->Save(u"../out/remove_comment.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:AddParentComments
}