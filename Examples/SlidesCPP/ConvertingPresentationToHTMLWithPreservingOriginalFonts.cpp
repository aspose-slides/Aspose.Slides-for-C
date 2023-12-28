#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void ConvertingPresentationToHTMLWithPreservingOriginalFonts()
{
    //ExStart:ConvertingPresentationToHTMLWithPreservingOriginalFonts

    const System::String outPath = u"../out/oHTMLWithPreservingOriginalFonts_out.html";
    const System::String templatePath = Path::Combine(GetDataPath(), u"input.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // exclude default presentation fonts
    System::ArrayPtr<System::String> fontNameExcludeList = System::MakeArray<System::String>({ u"Calibri", u"Arial" });

    System::SharedPtr<EmbedAllFontsHtmlController> embedFontsController = System::MakeObject<EmbedAllFontsHtmlController>(fontNameExcludeList);

    System::SharedPtr<HtmlOptions> htmlOptionsEmbed = System::MakeObject<HtmlOptions>();
    htmlOptionsEmbed->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(embedFontsController));

    System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
    options->set_NotesPosition(NotesPositions::BottomFull);
    htmlOptionsEmbed->set_SlidesLayoutOptions(options);

    pres->Save(outPath, SaveFormat::Html, htmlOptionsEmbed);

    //ExEnd:ConvertingPresentationToHTMLWithPreservingOriginalFonts

}
