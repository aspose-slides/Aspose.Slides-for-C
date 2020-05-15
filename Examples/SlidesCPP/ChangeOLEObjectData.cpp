#include "stdafx.h"
/*
#include "Publish/Factory.h" 
#include "Publish/IWorkbookMetadata.h"
#include "Publish/IWorkbookSettings.h"
#include "Publish/IWorksheet.h"
#include "Publish/IWorksheetCollection.h"
#include "Publish/IWorkbook.h"
#include "boost\intrusive_ptr.hpp"
#include "boost\smart_ptr\intrusive_ptr.hpp"

#include "Aspose.Cells.h"*/
#include "SlidesExamples.h"

//using namespace Aspose::Cells;
using namespace std;
using namespace Aspose::Slides;
using namespace System;
using namespace boost;

void ChangeOLEObjectData()
{
	// ExStart:ChangeOLEObjectData
	// The path to the documents directory.
	const String outPath = u"../out/ChangeOLEObjectData_out.xlsx";
	const String templatePath = u"../templates/AccessingOLEObjectFrame.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Cast the shape to OleObjectFrame
	SharedPtr<OleObjectFrame> oof = DynamicCast<OleObjectFrame>(slide->get_Shapes()->idx_get(0));

	// Read the OLE Object and write it to disk
	if (oof != nullptr)
	{
		/*
		System::ArrayPtr<uint8_t> buffer = oof->get_ObjectData();
		{
//			System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(outPath, System::IO::FileMode::Create, System::IO::FileAccess::Write, System::IO::FileShare::Read);
			System::SharedPtr<System::IO::MemoryStream> stream = System::MakeObject<System::IO::MemoryStream>(buffer);
			stream->set_Position(0);
			stream->Flush();
			stream->Close();

			// Reading object data in Workbook
			//Read input excel file
			boost::intrusive_ptr<Aspose::Cells::IWorkbook> workbook = Aspose::Cells::Factory::CreateIWorkbook("stream");

			//Accessing the first worksheet in the Excel file
			boost::intrusive_ptr<Aspose::Cells::IWorksheet> worksheet = workbook->GetIWorksheets()->GetObjectByIndex(0);

			//Get cells from sheet
			intrusive_ptr<Aspose::Cells::ICells> cells = worksheet->GetICells();


			using (System.IO.MemoryStream msln = new System.IO.MemoryStream(ole.ObjectData))
			{
				Wb = new Aspose.Cells.Workbook(msln);

				using (System.IO.MemoryStream msout = new System.IO.MemoryStream())
				{
					// Modifying the workbook data
					Wb.Worksheets[0].Cells[0, 4].PutValue("E");
					Wb.Worksheets[0].Cells[1, 4].PutValue(12);
					Wb.Worksheets[0].Cells[2, 4].PutValue(14);
					Wb.Worksheets[0].Cells[3, 4].PutValue(15);

					Aspose.Cells.OoxmlSaveOptions so1 = new Aspose.Cells.OoxmlSaveOptions(Aspose.Cells.SaveFormat.Xlsx);

					Wb.Save(msout, so1);

					// Changing Ole frame object data
					msout.Position = 0;
					ole.ObjectData = msout.ToArray();
				}
			}

		}*/
	}
	//ExEnd:ChangeOLEObjectData
}
