#include "stdafx.h"
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/SlideSizeType.h>
#include <Export/Pdfoptions.h>
#include <DOM/ShapeType.h>
#include <DOM/VideoFrame.h>
#include <DOM/IVideo.h>



#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>
#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include "ManageMedia.h"

using namespace Aspose::Slides;

using namespace System;
void::ManageMedia::ExtractVideo()
{
/*
	// ExStart:ExtractVideo
	// The path to the documents directory.
	const String templatePath = L"../templates/Video.pptx";
	const String outPath = L"../out/Video_out";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access the first slide
	SharedPtr<ISlideCollection> slides = pres->get_Slides()->idx_get(0);

	// Create a memory stream object
	SharedPtr<System::IO::MemoryStream> SvgStream = MakeObject<System::IO::MemoryStream>();


	for(int i=0;i< slides->get_Count();i++)
	{
		SharedPtr<ISlide> slide =slides->idx_get(i);

		for(int j=0;j<slide->get_Shapes()->get_Count();j++)
		{
			SharedPtr<IShape> shape = slide->get_Shapes()->idx_get(j);
	
			//auto smart = ExplicitCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

			if (shape->GetType()==Aspose::Slides::VideoFrame)
			{
				auto vf = ExplicitCast<Aspose::Slides::IVideoFrame>(shape);
				String type = vf->get_EmbeddedVideo()->get_ContentType();
				int ss = type->get_LastIndexOf('/');
				type = type.Remove(0, type.LastIndexOf('/') + 1);
				Byte[] buffer = vf.EmbeddedVideo.BinaryData;
				using (FileStream stream = new FileStream(dataDir + "NewVideo_out." + type, FileMode.Create, FileAccess.Write, FileShare.Read))
				{
					stream.Write(buffer, 0, buffer.Length);
				}
			}
		}
	}
	//ExEnd:ExtractVideo
}



	//ExStart:SetPDFPageSize
	//ExStart:RemoveHyperlinks

	// The path to the documents directory.
	const String outPath = L"../out/SetPDFPageSize_out.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation>pres = MakeObject<Presentation>();


	// Set SlideSize.Type Property 
	pres->get_SlideSize()->set_Type(SlideSizeType::A4Paper);

	// Set different properties of PDF Options
	Aspose::Slides::Export::PdfOptions opts = Aspose::Slides::Export::PdfOptions();
	opts.set_SufficientResolution(600);

	// Save presentation to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pdf, &opts);
	//ExEnd:SetPDFPageSize
	*/
}
