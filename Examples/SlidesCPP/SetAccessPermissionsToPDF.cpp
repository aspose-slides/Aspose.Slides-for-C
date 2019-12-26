#include<Dom/LoadOptions.h>
#include <DOM/Presentation.h>
#include<DOM/LoadOptions.h>
#include<DOM/ISlideCollection.h>
#include <Export/SaveFormat.h>
#include<DOM/ShapeType.h>
#include<DOM/IShapeCollection.h>
#include <Export/PdfOptions.h>
#include <Export/PdfAccessPermissions.h>
#include "SlidesExamples.h"


using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;


void SetAccessPermissionsToPDF() {

	//ExStart:SetAccessPermissionsToPDF
	
	const String pdfFilePath = u"../out/PDFWithPermissions.pdf";

	auto pdfOptions = System::MakeObject<PdfOptions>();
	pdfOptions->set_Password(u"my_password");

	pdfOptions->set_AccessPermissions(Aspose::Slides::Export::PdfAccessPermissions::PrintDocument | Aspose::Slides::Export::PdfAccessPermissions::HighQualityPrint);

	auto presentation = System::MakeObject<Presentation>();

	presentation->Save(pdfFilePath, Aspose::Slides::Export::SaveFormat::Pdf, pdfOptions);

	//ExEnd:SetAccessPermissionsToPDF


}