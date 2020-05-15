#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void RenderingNotesWhileConvertingToHTML() {

	//ExStart:RenderingNotesWhileConvertingToHTML

	const String outPath = u"../out/HTML_Notes_out.hmtl";
	const String templatePath = u"../templates/AccessSlides.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    SharedPtr<HtmlOptions> htmlOptions = MakeObject<HtmlOptions>();

	SharedPtr<INotesCommentsLayoutingOptions> options = htmlOptions->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);

	pres->Save(outPath, SaveFormat::Html, htmlOptions);

	//ExEnd:RenderingNotesWhileConvertingToHTML

}
