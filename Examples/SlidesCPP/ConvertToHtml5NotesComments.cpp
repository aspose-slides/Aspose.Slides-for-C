#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;

void ConvertToHtml5NotesComments()
{
    const System::String templatePath = Path::Combine(GetDataPath(), u"ConvertWithNote.pptx");
    const System::String outHtmlPath = Path::Combine(GetOutPath(), u"Html5NotesResult.html");
    const System::String outPath = Path::Combine(GetOutPath(), u"Html5NotesResult");

    // Instantiate a Presentation object that represents a presentation file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    auto notesCommentsLayouting = System::MakeObject<NotesCommentsLayoutingOptions>();
    notesCommentsLayouting->set_NotesPosition(NotesPositions::BottomTruncated);

    auto html5Options = System::MakeObject<Html5Options>();
    html5Options->set_OutputPath(u"");
    html5Options->set_NotesCommentsLayouting(notesCommentsLayouting);

    // Save a result
    pres->Save(outHtmlPath, SaveFormat::Html5, html5Options);
}
