#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Background.h>
#include <DOM/BackgroundType.h>
#include <DOM/GradientFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>
#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>
#include <DOM/IEffectFormat.h>
#include <DOM/Effects/IInnerShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>

#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/TextVerticalType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAutofitType.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/Effects/IOuterShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/IHyperlinkManager.h>
#include <DOM/ColorType.h>
#include <DOM/OleObjectFrame.h>
#include <DOM/IOleObjectFrame.h>
#include <DOM/AudioPlayModePreset.h>
#include <DOM/AudioVolumeMode.h>

#include <system/io/file_stream.h>
#include <system/io/file_share.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/details/dispose_guard.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;


void AddOLEObjectFrame()
{

	// ExStart:AddOLEObjectFrame
	// The path to the documents directory.
	const String outPath = L"../out/AddOLEObjectFrame_out.pptx";
	const String filePath = L"../templates/book1.xlsx";


	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Save file to memory stream 
	{
		System::SharedPtr<System::IO::Stream> fileStream = System::IO::File::OpenRead(filePath);
		System::SharedPtr<System::IO::MemoryStream> MemStream = MakeObject< System::IO::MemoryStream>();

		System::ArrayPtr<uint8_t> buffer = System::MakeObject<System::Array<uint8_t>>(4 * 1024, 0);
		int32_t len;
		while ((len = fileStream->Read(buffer, 0, buffer->get_Length())) > 0)
		{
			MemStream->Write(buffer, 0, len);
		}
		MemStream->set_Position(0);

		// Add an Ole Object Frame shape
		System::SharedPtr<IOleObjectFrame> oof = slide->get_Shapes()->AddOleObjectFrame(0, 0, 720, 540, L"Excel.Sheet.12", MemStream->ToArray());
	}


	//Write the PPTX file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddOLEObjectFrame
}
