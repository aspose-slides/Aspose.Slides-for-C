#include <iostream>

#include <system/console.h>
#include <system/exception.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <Export/TiffOptions.h>
#include <Export/SwfOptions.h>
#include <Export/NotesPositions.h>
#include <Export/INotesCommentsLayoutingOptions.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include "SlidesExamples.h"


using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
using namespace System::Drawing::Imaging;

const String templatePath = u"../templates/TestDeck_050.pptx";

void SamplePDF()
{
	try {
		auto pres = MakeObject<Presentation>(templatePath);

		pres->Save(u"../out/SampleAddText.pdf", Export::SaveFormat::Pdf);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(u"Running Exports::PDF...");
		System::Console::WriteLine(e.get_Message());


	}
}
void SampleHTML()
{
	try{
		auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(u"../out/SampleAddText.html", Export::SaveFormat::Html);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(u"Running Exports::HTML...");
		System::Console::WriteLine(e.get_Message());


	}
}
void SampleXPS()
{
	try{
	auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(u"../out/SampleAddText.xps", Export::SaveFormat::Xps);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(u"Running Exports::XPS...");
		System::Console::WriteLine(e.get_Message());


	}
}
void SampleTIFF()
{
	try{
	auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(u"../out/SampleAddText_Tiff.tiff", Export::SaveFormat::Tiff);

	System::SharedPtr<TiffOptions> tiffOptions = System::MakeObject<TiffOptions>();
	System::SharedPtr<INotesCommentsLayoutingOptions> options = tiffOptions->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);

	pres->Save(u"../out/SampleAddText_TiffNotes.tiff", Export::SaveFormat::Tiff, tiffOptions);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(L"Running Exports::Tiff...");
		System::Console::WriteLine(e.get_Message());


	}
}
void SampleSWF()
{
	try
	{ 
	auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(u"../out/SampleAddText_Swf.swf", Export::SaveFormat::Swf);

	System::SharedPtr<SwfOptions> swfOptions = System::MakeObject<SwfOptions>();
	System::SharedPtr<INotesCommentsLayoutingOptions> options = swfOptions->get_NotesCommentsLayouting();
	options->set_NotesPosition(NotesPositions::BottomFull);

	pres->Save(u"../out/SampleAddText_SwfNote.swf", Export::SaveFormat::Swf, swfOptions);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(u"Running Exports::SWF...");
		System::Console::WriteLine(e.get_Message());


	}
}