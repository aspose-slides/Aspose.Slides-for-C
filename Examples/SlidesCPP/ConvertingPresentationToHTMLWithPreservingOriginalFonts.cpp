#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void ConvertingPresentationToHTMLWithPreservingOriginalFonts()
{
	//ExStart:ConvertingPresentationToHTMLWithPreservingOriginalFonts

	const String outPath = u"../out/oHTMLWithPreservingOriginalFonts_out.html";
    const String templatePath = Path::Combine(GetDataPath(), u"input.pptx");

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// exclude default presentation fonts
	ArrayPtr<String> fontNameExcludeList = MakeArray<String>( { u"Calibri", u"Arial" });

	SharedPtr<EmbedAllFontsHtmlController> embedFontsController = MakeObject<EmbedAllFontsHtmlController>(fontNameExcludeList);

	SharedPtr<HtmlOptions> htmlOptionsEmbed = MakeObject<HtmlOptions>();
	htmlOptionsEmbed->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(embedFontsController));

	SharedPtr<INotesCommentsLayoutingOptions> options = htmlOptionsEmbed->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);

	pres->Save(outPath, SaveFormat::Html, htmlOptionsEmbed);

	//ExEnd:ConvertingPresentationToHTMLWithPreservingOriginalFonts

}
