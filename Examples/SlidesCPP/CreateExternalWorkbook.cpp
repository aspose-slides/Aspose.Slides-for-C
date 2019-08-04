#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IChart.h>
#include <DOM/Chart/ChartData.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/IChartDataWorkbook.h>

#include <Export/SaveFormat.h>
#include <system/io/file.h>

#include "SlidesExamples.h"


using namespace Aspose::Slides;
using namespace System;


void CreateExternalWorkbook()
{
	//ExStart:CreateExternalWorkbook

	const String templatePath = u"../templates/presentaion.pptx";
	const String externalWbPath = u"../externalWorkbook1.pptx";


	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	

	System::SharedPtr<Aspose::Slides::Charts::IChart> chart = pres->get_Slides()->idx_get(0)->get_Shapes()->AddChart(Aspose::Slides::Charts::ChartType::Pie, 50.0f, 50.0f, 400.0f, 600.0f);

	if (System::IO::File::Exists(externalWbPath))
		System::IO::File::Delete(externalWbPath);

	System::SharedPtr<System::IO::FileStream> fileStream = System::MakeObject<System::IO::FileStream>(externalWbPath, System::IO::FileMode::CreateNew);
	System::ArrayPtr<uint8_t> worbookData = chart->get_ChartData()->ReadWorkbookStream()->ToArray();
	fileStream->Write(worbookData, 0, worbookData->get_Length());
	fileStream->Close();

	chart->get_ChartData()->SetExternalWorkbook(externalWbPath);

	//ExEnd:CreateExternalWorkbook
}