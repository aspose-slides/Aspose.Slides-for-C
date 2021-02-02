#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SetAccessPermissionsToPDF()
{
	//ExStart:SetAccessPermissionsToPDF
	
	const String pdfFilePath = u"../out/PDFWithPermissions.pdf";

	auto pdfOptions = System::MakeObject<PdfOptions>();
	pdfOptions->set_Password(u"my_password");

	pdfOptions->set_AccessPermissions(PdfAccessPermissions::PrintDocument | PdfAccessPermissions::HighQualityPrint);

	auto presentation = System::MakeObject<Presentation>();

	presentation->Save(pdfFilePath, SaveFormat::Pdf, pdfOptions);

	//ExEnd:SetAccessPermissionsToPDF
}
