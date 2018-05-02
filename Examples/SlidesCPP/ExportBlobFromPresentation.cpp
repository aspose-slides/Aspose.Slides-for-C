/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Slides for .NET API reference 
when the project is build. Please check https://docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Slides for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/
#include "ExportBlobFromPresentation.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/stream.h>
#include <system/io/file_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/array.h>
#include <PresentationLockingBehavior.h>
#include <IBlobManagementOptions.h>
#include <DOM/Presentation.h>
#include <DOM/LoadOptions.h>
#include <DOM/IVideoCollection.h>
#include <DOM/IVideo.h>
#include <cstdint>

#include "SlidesExamples.h"

namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Presentations {

namespace Conversion {

RTTI_INFO_IMPL_HASH(256518863u, ::Aspose::Slides::Examples::CSharp::Presentations::Conversion::ExportBlobFromPresentation, ThisTypeBaseTypesInfo);

void ExportBlobFromPresentation::Run()
{
    //ExStart:ExportBlobFromPresentation
    // The path to the documents directory.
	const String outPath = u"../out/";
	const String templatePath = u"../templates/Video.pptx";

    System::SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
    loadOptions->get_BlobManagementOptions()->set_PresentationLockingBehavior(Aspose::Slides::PresentationLockingBehavior::KeepLocked);
    // lock the source file and don't load it into memory
    
    // create the Presentation's instance, lock the "hugePresentationWithAudiosAndVideos.pptx" file.
    {
        System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath, loadOptions);
        
        // Clearing resources under 'using' statement
        //System::Details::DisposeGuard __dispose_guard_0{ pres, ASPOSE_CURRENT_FUNCTION };
        // ------------------------------------------
        // let's save each video to a file. to prevent memory usage we need a buffer which will be used
        // to exchange tha data from the presentation's video stream to a stream for newly created video file.
        System::ArrayPtr<uint8_t> buffer = System::MakeArray<uint8_t>(8 * 1024, 0);
        
        // iterate through the videos
        for (int32_t index = 0; index < pres->get_Videos()->get_Count(); index++)
        {
            System::SharedPtr<IVideo> video = pres->get_Videos()->idx_get(index);
            
            // open the presentation video stream. Please note that we intentionally avoid accessing properties
            // like video.BinaryData - this property returns a byte array containing full video, and that means
            // this bytes will be loaded into memory. We will use video.GetStream, which will return Stream and
            // that allows us to not load the whole video into memory.
            {
                System::SharedPtr<System::IO::Stream> presVideoStream = video->GetStream();
                
                // Clearing resources under 'using' statement
                //System::Details::DisposeGuard __dispose_guard_1{ presVideoStream, ASPOSE_CURRENT_FUNCTION };
                // ------------------------------------------
                {
                    System::SharedPtr<System::IO::FileStream> outputFileStream = System::IO::File::OpenWrite(outPath+System::String::Format(u"video{0}.avi",index));
                    
                    // Clearing resources under 'using' statement
                    //System::Details::DisposeGuard __dispose_guard_2{ outputFileStream, ASPOSE_CURRENT_FUNCTION };
                    // ------------------------------------------
                    int32_t bytesRead;
                    while ((bytesRead = presVideoStream->Read(buffer, 0, buffer->get_Length())) > 0)
                    {
                        outputFileStream->Write(buffer, 0, bytesRead);
                    }
                }
            }
            
            // memory consumption will stay low no matter what size the videos or presentation is.
        }
        
		//ExEnd:ExportBlobFromPresentation

        // do the same for audios if needed.
    }
    
}

} // namespace Conversion
} // namespace Presentations
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose
