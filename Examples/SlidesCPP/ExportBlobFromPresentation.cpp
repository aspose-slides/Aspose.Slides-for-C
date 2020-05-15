#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ExportBlobFromPresentation()
{
    //ExStart:ExportBlobFromPresentation
    // The path to the documents directory.
	const String outPath = u"../out/";
	const String templatePath = u"../templates/Video.pptx";

    SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
    // lock the source file and don't load it into memory
    loadOptions->get_BlobManagementOptions()->set_PresentationLockingBehavior(PresentationLockingBehavior::KeepLocked);
    
    // create the Presentation's instance, lock the "Video.pptx" file.
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath, loadOptions);
    
    // let's save each video to a file. to prevent memory usage we need a buffer which will be used
    // to exchange tha data from the presentation's video stream to a stream for newly created video file.
    ArrayPtr<uint8_t> buffer = System::MakeArray<uint8_t>(8 * 1024, 0);
    
    // iterate through the videos
    for (int32_t index = 0; index < pres->get_Videos()->get_Count(); index++)
    {
        SharedPtr<IVideo> video = pres->get_Videos()->idx_get(index);
        
        // open the presentation video stream. Please note that we intentionally avoid accessing properties
        // like video.BinaryData - this property returns a byte array containing full video, and that means
        // this bytes will be loaded into memory. We will use video.GetStream, which will return Stream and
        // that allows us to not load the whole video into memory.

        SharedPtr<IO::Stream> presVideoStream = video->GetStream();
            
        SharedPtr<IO::FileStream> outputFileStream = IO::File::OpenWrite(outPath+String::Format(u"video{0}.avi",index));

        int32_t bytesRead;
        while ((bytesRead = presVideoStream->Read(buffer, 0, buffer->get_Length())) > 0)
        {
            outputFileStream->Write(buffer, 0, bytesRead);
        }
        
        // memory consumption will stay low no matter what size the videos or presentation is.
    }

    // do the same for audios if needed.

	//ExEnd:ExportBlobFromPresentation
}
