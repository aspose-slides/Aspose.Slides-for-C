#include <system/object_ext.h>
#include<Dom/ProtectionManager.h>
#include <DOM/Presentation.h>
#include<Dom/IProtectionManager.h>
#include <Export/SaveFormat.h>
#include <Export/EmbedAllFontsHtmlController.h>
#include <Export/HtmlOptions.h>
#include <Export/HtmlFormatter.h>
#include <Export/NotesPositions.h>
#include <Export/INotesCommentsLayoutingOptions.h>

#include<Dom/CommonSlideViewProperties.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;
void ConvertingPresentationToHTMLWithPreservingOriginalFonts() {

	//ExStart:ConvertingPresentationToHTMLWithPreservingOriginalFonts

	const String outPath = u"../out/oHTMLWithPreservingOriginalFonts_out.hmtl";
	const String templatePath = u"../templates/AccessSlides.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// exclude default presentation fonts
	ArrayPtr<String> fontNameExcludeList =MakeArray<String>( { u"Calibri", u"Arial" });

	SharedPtr<EmbedAllFontsHtmlController> embedFontsController = MakeObject< EmbedAllFontsHtmlController>(fontNameExcludeList);

	SharedPtr<HtmlOptions> htmlOptionsEmbed = MakeObject<  HtmlOptions>();
	htmlOptionsEmbed->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(embedFontsController));

	System::SharedPtr<INotesCommentsLayoutingOptions> options = htmlOptionsEmbed->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Html, htmlOptionsEmbed);

	//ExEnd:ConvertingPresentationToHTMLWithPreservingOriginalFonts

}