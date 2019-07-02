#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <Export/PdfOptions.h>
#include <Export/SaveOptions.h>
#include <Export/ISaveOptions.h>
#include <DOM/IGenericCloneable.h>
#include <IProgressCallback.h>
#include <system/string.h>
#include "SlidesExamples.h"
#include <system/console.h>
using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

//ExStart:ExportProgressHandler
class ExportProgressHandler : public IProgressCallback
{
public:
	void Reporting(double progressValue)
	{
		System::Console::WriteLine(u"% completed", progressValue);
		
	}
};
//ExEnd:ExportProgressHandler
void CovertToPDFWithProgressUpdate()
{

	//ExStart:CovertToPDFWithProgressUpdate

	const String templatePath = u"../templates/SamplePresentation.pptx";
	const String outPath = u"../out/SamplePresentation_out.pptx";

	auto presentation = System::MakeObject<Presentation>(templatePath);

	System::SharedPtr<ISaveOptions> saveOptions = System::MakeObject<PdfOptions>();

	System::SharedPtr<IProgressCallback> callBack = System::MakeObject<ExportProgressHandler>();

	saveOptions->set_ProgressCallback(callBack);
	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, saveOptions);

	//ExEnd:CovertToPDFWithProgressUpdate

}

