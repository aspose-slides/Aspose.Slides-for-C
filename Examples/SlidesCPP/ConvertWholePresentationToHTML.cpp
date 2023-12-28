#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

void ConvertWholePresentationToHTML()
{
    //ExStart:ConvertWholePresentationToHTML

    // The path to the documents directory.
    const System::String outPath = u"../out/ConvertWholePresentationToHTML_out.html";
    const System::String templatePath = u"../templates/AccessSlides.pptx";

    //Instantiate Presentation class that represents PPTX file
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    System::SharedPtr<ResponsiveHtmlController> controller = System::MakeObject<ResponsiveHtmlController>();
    
    System::SharedPtr<HtmlOptions> htmlOptions = System::MakeObject<HtmlOptions>();
    htmlOptions->set_HtmlFormatter((HtmlFormatter::CreateSlideShowFormatter(u"", false)));

    System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
    options->set_NotesPosition(NotesPositions::BottomFull);
    htmlOptions->set_SlidesLayoutOptions(options);
    
    pres->Save(outPath, SaveFormat::Html, htmlOptions);

    //ExEnd:ConvertWholePresentationToHTML
}
