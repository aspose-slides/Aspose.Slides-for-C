
#include <system/object_ext.h>
#include <system/console.h>

#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <DOM/LoadOptions.h>
#include <IBlobManagementOptions.h>
#include <IFontSources.h>
#include <system\io\file.h>
//#include <Metered\Imported\Metered.h>
//#include <Metered\Imported\Metered.h>
#include <Util/License.h>



#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
using namespace System::IO;

void MeteredLicencing()
{

	//ExStart:MeteredLicencing
	
	// The path to the documents directory.
	const String outPath = u"../out/ConvertToPDF_out.pdf";
	const String templatePath = u"../templates/AccessSlides.pptx";

	// Create an instance of Slides Metered class
	SharedPtr<Metered> metered = MakeObject<Metered>();

	// Access the setMeteredKey property and pass public and private keys as parameters
	metered->SetMeteredKey(u"*****", u"*****");

	// Get metered data amount before calling API
	auto amountbefore = Aspose::Slides::Metered::GetConsumptionQuantity();

	// Display information
	System::Console::WriteLine(u"Amount Consumed Before: {0}", amountbefore.ToString());

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf);


	// Get metered data amount After calling API
	auto amountafter = Aspose::Slides::Metered::GetConsumptionQuantity();

	// Display information
	System::Console::WriteLine(u"Amount Consumed After: {0}", amountafter.ToString());

	//ExEnd:MeteredLicencing
}