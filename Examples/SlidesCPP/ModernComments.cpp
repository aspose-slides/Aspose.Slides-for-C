#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;
using System::Drawing::PointF;

void ModernComments()
{
    // The path to the output file.
    String outPptxFile = Path::Combine(GetOutPath(), u"ModernComments_out.pptx");

    auto pres = System::MakeObject<Presentation>();
    
    // Add author
    auto newAuthor = pres->get_CommentAuthors()->AddAuthor(u"Some Author", u"SA");

    // Add comment
    auto point = PointF(100.0f, 100.0f);
    auto text = u"This is a modern comment";
    auto slide = pres->get_Slides()->idx_get(0);
    auto modernComment = newAuthor->get_Comments()->AddModernComment(text, slide, nullptr, point, DateTime::get_Now());

    // Save presentation
    pres->Save(outPptxFile, Export::SaveFormat::Pptx);
}