#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;
using namespace System::Drawing::Imaging;

const String templatePath = u"../templates/TestDeck_050.pptx";

void SamplePDF()
{
	try
    {
		auto pres = MakeObject<Presentation>(templatePath);

		pres->Save(u"../out/SampleAddText.pdf", SaveFormat::Pdf);
	}
	catch (Exception e)
	{
		Console::WriteLine(u"Running Exports::PDF...");
		Console::WriteLine(e->get_Message());
	}
}

void SampleHTML()
{
	try
    {
		auto pres = MakeObject<Presentation>(templatePath);

	    pres->Save(u"../out/SampleAddText.html", SaveFormat::Html);
	}
	catch (Exception e)
	{
		Console::WriteLine(u"Running Exports::HTML...");
		Console::WriteLine(e->get_Message());
	}
}

void SampleXPS()
{
	try
    {
	    auto pres = MakeObject<Presentation>(templatePath);

	    pres->Save(u"../out/SampleAddText.xps", SaveFormat::Xps);
	}
	catch (Exception e)
	{
		Console::WriteLine(u"Running Exports::XPS...");
		Console::WriteLine(e->get_Message());
	}
}

void SampleTIFF()
{
	try
    {
	    auto pres = MakeObject<Presentation>(templatePath);

	    pres->Save(u"../out/SampleAddText_Tiff.tiff", SaveFormat::Tiff);

	    SharedPtr<TiffOptions> tiffOptions = System::MakeObject<TiffOptions>();
	    SharedPtr<INotesCommentsLayoutingOptions> options = tiffOptions->get_NotesCommentsLayouting();
	    options->set_NotesPosition(NotesPositions::BottomFull);

	    pres->Save(u"../out/SampleAddText_TiffNotes.tiff", SaveFormat::Tiff, tiffOptions);
	}
	catch (Exception e)
	{
		Console::WriteLine(L"Running Exports::Tiff...");
		Console::WriteLine(e->get_Message());
	}
}

void SampleSWF()
{
	try
	{ 
	    auto pres = MakeObject<Presentation>(templatePath);

	    pres->Save(u"../out/SampleAddText_Swf.swf", SaveFormat::Swf);

	    SharedPtr<SwfOptions> swfOptions = System::MakeObject<SwfOptions>();
	    SharedPtr<INotesCommentsLayoutingOptions> options = swfOptions->get_NotesCommentsLayouting();
	    options->set_NotesPosition(NotesPositions::BottomFull);

	    pres->Save(u"../out/SampleAddText_SwfNote.swf", SaveFormat::Swf, swfOptions);
	}
	catch (Exception e)
	{
		Console::WriteLine(u"Running Exports::SWF...");
		Console::WriteLine(e->get_Message());
	}
}
