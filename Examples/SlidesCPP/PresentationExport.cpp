#include <iostream>

#include <system/console.h>
#include <system/exception.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "PresentationExport.h"

using namespace Aspose::Slides;

using namespace System;
using namespace System::Drawing::Imaging;

const String templatePath = L"../templates/TestDeck_050.pptx";

void PresentationExport::SamplePDF()
{
	try {
		auto pres = MakeObject<Presentation>(templatePath);

		pres->Save(L"../out/SampleAddText.pdf", Export::SaveFormat::Pdf);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(L"Running Exports::PDF...");
		System::Console::WriteLine(e.get_Message());


	}
}
void PresentationExport::SampleHTML()
{
	try{
		auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(L"../out/SampleAddText.html", Export::SaveFormat::Html);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(L"Running Exports::HTML...");
		System::Console::WriteLine(e.get_Message());


	}
}
void PresentationExport::SampleXPS()
{
	try{
	auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(L"../out/SampleAddText.xps", Export::SaveFormat::Xps);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(L"Running Exports::XPS...");
		System::Console::WriteLine(e.get_Message());


	}
}
void PresentationExport::SampleTIFF()
{
	try{
	auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(L"../out/SampleAddText_Tiff.tiff", Export::SaveFormat::Tiff);
	pres->Save(L"../out/SampleAddText_TiffNotes.tiff", Export::SaveFormat::TiffNotes);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(L"Running Exports::Tiff...");
		System::Console::WriteLine(e.get_Message());


	}
}
void PresentationExport::SampleSWF()
{
	try
	{ 
	auto pres = MakeObject<Presentation>(templatePath);

	pres->Save(L"../out/SampleAddText_Swf.swf", Export::SaveFormat::Swf);
	pres->Save(L"../out/SampleAddText_SwfNote.swf", Export::SaveFormat::SwfNotes);
	}
	catch (Exception e)
	{
		System::Console::WriteLine(L"Running Exports::SWF...");
		System::Console::WriteLine(e.get_Message());


	}
}