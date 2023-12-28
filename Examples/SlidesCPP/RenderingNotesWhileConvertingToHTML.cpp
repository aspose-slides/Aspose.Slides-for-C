#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void RenderingNotesWhileConvertingToHTML() {

    //ExStart:RenderingNotesWhileConvertingToHTML

    const System::String outPath = u"../out/HTML_Notes_out.hmtl";
    const System::String templatePath = u"../templates/AccessSlides.pptx";

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    System::SharedPtr<HtmlOptions> htmlOptions = System::MakeObject<HtmlOptions>();
    System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
    options->set_NotesPosition(NotesPositions::BottomFull);
    htmlOptions->set_SlidesLayoutOptions(options);

    pres->Save(outPath, SaveFormat::Html, htmlOptions);

    //ExEnd:RenderingNotesWhileConvertingToHTML
}
