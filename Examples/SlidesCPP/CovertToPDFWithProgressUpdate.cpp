#include "stdafx.h"
#include <IProgressCallback.h>
#include "SlidesExamples.h"

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
		Console::WriteLine(u"{0}% completed", progressValue);
	}
};
//ExEnd:ExportProgressHandler

void CovertToPDFWithProgressUpdate()
{
	//ExStart:CovertToPDFWithProgressUpdate

	const String templatePath = u"../templates/SamplePresentation.pptx";
	const String outPath = u"../out/SamplePresentation_out.pptx";

	auto presentation = System::MakeObject<Presentation>(templatePath);

	SharedPtr<ISaveOptions> saveOptions = System::MakeObject<PdfOptions>();

	SharedPtr<IProgressCallback> callBack = System::MakeObject<ExportProgressHandler>();

	saveOptions->set_ProgressCallback(callBack);
	presentation->Save(outPath, SaveFormat::Pdf, saveOptions);

	//ExEnd:CovertToPDFWithProgressUpdate
}
