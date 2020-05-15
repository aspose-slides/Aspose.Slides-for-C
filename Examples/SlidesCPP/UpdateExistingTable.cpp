#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void UpdateExistingTable()
{
	// ExStart:UpdateExistingTable
	// The path to the documents directory.
	const String outPath = u"../out/UpdateExistingTable_out.pptx";
	const String templatePath = u"../templates/TestTable.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> islide = pres->get_Slides()->idx_get(0);

	// Add table shape to slide
	SharedPtr<Table> table = System::DynamicCast<Table>(islide->get_Shapes()->idx_get(0));

	// Set the text of the first column of second row
	table->idx_get(0, 1)->get_TextFrame()->set_Text(u"New");

	// Save PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:UpdateExistingTable
}
