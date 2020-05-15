#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void CreateExternalWorkbook()
{
	//ExStart:CreateExternalWorkbook

	const String templatePath = u"../templates/presentation.pptx";
	const String externalWbPath = GetOutPath() + u"externalWorkbook1.xlsx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	
	SharedPtr<Charts::IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Charts::ChartType::Pie, 50.0f, 50.0f, 400.0f, 600.0f);

	if (IO::File::Exists(externalWbPath))
		IO::File::Delete(externalWbPath);

	SharedPtr<IO::FileStream> fileStream = System::MakeObject<IO::FileStream>(externalWbPath, IO::FileMode::CreateNew);
	ArrayPtr<uint8_t> worbookData = chart->get_ChartData()->ReadWorkbookStream()->ToArray();
	fileStream->Write(worbookData, 0, worbookData->get_Length());
	fileStream->Close();

	chart->get_ChartData()->SetExternalWorkbook(externalWbPath);

	//ExEnd:CreateExternalWorkbook
}
