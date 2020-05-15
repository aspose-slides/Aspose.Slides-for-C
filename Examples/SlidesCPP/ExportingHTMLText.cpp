#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace Text;

void ExportingHTMLText()
{
	// ExStart:ExportingHTMLText
	// The path to the documents directory.
	const String outPath = u"../out/output.html";
	const String templatePath = u"../templates/DefaultFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Acesss the default first slide of presentation
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Desired index
	int index = 0;

	// Accessing the added shape
	SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(0);

	SharedPtr<AutoShape> ashape = DynamicCast<AutoShape>(shape);

	// Extracting first paragraph as HTML
	SharedPtr<IO::StreamWriter> sw = MakeObject<IO::StreamWriter>(outPath, false, Encoding::get_UTF8());

	//Writing Paragraphs data to HTML by providing paragraph starting index, total paragraphs to be copied
	sw->Write(ashape->get_TextFrame()->get_Paragraphs()->ExportToHtml(0, ashape->get_TextFrame()->get_Paragraphs()->get_Count(), nullptr));

	sw->Close();

	// ExEnd:ExportingHTMLText
}
