#include "stdafx.h"
#include "SlidesExamples.h"

#include "Publish/Factory.h" 
#include "Publish/IWorksheet.h"
#include "Publish/IWorksheetCollection.h"
#include "Publish/ICell.h"
#include "Publish/ICells.h"
#include "Publish/IWorkbook.h"
#include "boost\smart_ptr\intrusive_ptr.hpp"

using namespace Aspose::Slides;
using namespace Aspose::Slides::DOM::Ole;
using namespace boost;

intrusive_ptr<Aspose::Cells::Systems::IO::MemoryStream> ToCellsMemoryStream(System::ArrayPtr<uint8_t> buffer)
{
    intrusive_ptr<BString> array = new BString(buffer->data_ptr(), buffer->Count());
    auto stream = new Aspose::Cells::Systems::IO::MemoryStream(array);

    return stream;
}

System::SharedPtr<System::IO::MemoryStream> ToSlidesMemoryStream(intrusive_ptr<Aspose::Cells::Systems::IO::MemoryStream> inputStream)
{
    System::ArrayPtr<uint8_t> outputBuffer = System::MakeArray<uint8_t>(inputStream->GetLength(), inputStream->GetBuffer()->ArrayPoint());
    auto outputStream = System::MakeObject<System::IO::MemoryStream>(outputBuffer);

    return outputStream;
}

void ChangeOLEObjectData()
{
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(GetDataPath() + u"ChangeOLEObjectData.pptx");
    System::SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    System::SharedPtr<OleObjectFrame> ole;

    // Traversing all shapes for Ole frame
    for (auto shape : slide->get_Shapes())
    {
        if (System::ObjectExt::Is<OleObjectFrame>(shape))
        {
            ole = System::DynamicCast<OleObjectFrame>(shape);
        }
    }
    
    if (ole != nullptr)
    {
        // Reading object data in Workbook
        intrusive_ptr<Aspose::Cells::Systems::IO::MemoryStream> cellsInputStream = ToCellsMemoryStream(ole->get_EmbeddedData()->get_EmbeddedFileData());
        intrusive_ptr<Aspose::Cells::IWorkbook> Wb = Aspose::Cells::Factory::CreateIWorkbook(cellsInputStream);

        // Modifying the workbook data
        Wb->GetIWorksheets()->GetObjectByIndex(0)->GetICells()->GetObjectByIndex(0,4)->PutValue(u"E");
        Wb->GetIWorksheets()->GetObjectByIndex(0)->GetICells()->GetObjectByIndex(1, 4)->PutValue(12);
        Wb->GetIWorksheets()->GetObjectByIndex(0)->GetICells()->GetObjectByIndex(2, 4)->PutValue(14);
        Wb->GetIWorksheets()->GetObjectByIndex(0)->GetICells()->GetObjectByIndex(3, 4)->PutValue(15);

        intrusive_ptr<MemoryStream> cellsOutputStream = new Aspose::Cells::Systems::IO::MemoryStream();
        Wb->Save(cellsOutputStream, Aspose::Cells::SaveFormat_Xlsx);
        
        // Changing Ole frame object data
        cellsOutputStream->SetPosition(0);
        System::SharedPtr<System::IO::MemoryStream> msout = ToSlidesMemoryStream(cellsOutputStream);

        System::SharedPtr<IOleEmbeddedDataInfo> newData = System::MakeObject<OleEmbeddedDataInfo>(msout->ToArray(), ole->get_EmbeddedData()->get_EmbeddedFileExtension());
        ole->SetEmbeddedData(newData);

        pres->Save(GetOutPath() + u"OleEdit_out.pptx", Export::SaveFormat::Pptx);
    }
}
