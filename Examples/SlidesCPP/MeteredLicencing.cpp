#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;
using namespace IO;

void MeteredLicencing()
{
	//ExStart:MeteredLicencing
	
	// The path to the documents directory.
	const String outPath = u"../out/ConvertToPDF_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";

	// Create an instance of Slides Metered class
	//SharedPtr<Metered> metered = MakeObject<Metered>();

	// Access the setMeteredKey property and pass public and private keys as parameters
	//metered->SetMeteredKey(u"*****", u"*****");

	// Get metered data amount before calling API
	//auto amountbefore = Aspose::Slides::Metered::GetConsumptionQuantity();

	// Display information
	//System::Console::WriteLine(u"Amount Consumed Before: {0}", amountbefore.ToString());

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	pres->Save(outPath, SaveFormat::Pdf);

	// Get metered data amount After calling API
    //auto amountafter = Aspose::Slides::Metered::GetConsumptionQuantity();

	// Display information
	//System::Console::WriteLine(u"Amount Consumed After: {0}", amountafter.ToString());

	// Print status of a Metered license.
	//System::Console::WriteLine(u"Is metered license accepted: {0}", Aspose::Slides::Metered::IsMeteredLicensed());

	//ExEnd:MeteredLicencing
}
