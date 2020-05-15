#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddParentComments()
{
	//ExStart:AddParentComments

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	// Add comment
	SharedPtr<ICommentAuthor> author1 = pres->get_CommentAuthors()->AddAuthor(u"Author_1", u"A.A.");
	SharedPtr<IComment> comment1 = author1->get_Comments()->AddComment(u"comment1", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());

	// Add reply for comment1
	SharedPtr<ICommentAuthor> author2 = pres->get_CommentAuthors()->AddAuthor(u"Autror_2", u"B.B.");
	SharedPtr<IComment> reply1 = author2->get_Comments()->AddComment(u"reply 1 for comment 1", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());
	reply1->set_ParentComment(comment1);

	// Add reply for comment1
	SharedPtr<IComment> reply2 = author2->get_Comments()->AddComment(u"reply 2 for comment 1", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());
	reply2->set_ParentComment(comment1);

	// Add reply to reply
	SharedPtr<IComment> subReply = author1->get_Comments()->AddComment(u"subreply 3 for reply 2", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());
	subReply->set_ParentComment(reply2);

	SharedPtr<IComment> comment2 = author2->get_Comments()->AddComment(u"comment 2", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());
	SharedPtr<IComment> comment3 = author2->get_Comments()->AddComment(u"comment 3", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());

	SharedPtr<IComment> reply3 = author1->get_Comments()->AddComment(u"reply 4 for comment 3", pres->get_Slides()->idx_get(0), System::Drawing::PointF(10.0f, 10.0f), DateTime::get_Now());
	reply3->set_ParentComment(comment3);

	// Display hierarchy on console
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
	auto comments = slide->GetSlideComments(nullptr);
	for (int32_t i = 0; i < comments->get_Length(); i++)
	{
		SharedPtr<IComment> comment = comments[i];
		while (comment->get_ParentComment() != nullptr)
		{
			Console::Write(u"\t");
			comment = comment->get_ParentComment();
		}

		Console::Write(u"{0} : {1}", ObjectExt::Box<String>(comments[i]->get_Author()->get_Name()), ObjectExt::Box<String>(comments[i]->get_Text()));
		Console::WriteLine();
	}
	pres->Save(u"../out/parent_comment.pptx", Export::SaveFormat::Pptx);
	// Remove comment1 and all its replies
	comment1->Remove();

	pres->Save(u"../out/remove_comment.pptx", Export::SaveFormat::Pptx);
	//ExEnd:AddParentComments
}
