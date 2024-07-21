#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

static void GetOleObjectFrameCount(SharedPtr<ISlideCollection> slides, int& oleFramesCount, int& emptyOleFramesCount)
{
    oleFramesCount = 0;
    emptyOleFramesCount = 0;

    for (auto&& slide : slides)
    {
        for (auto&& shape : slide->get_Shapes())
        {
            SharedPtr<OleObjectFrame> oleObjectFrame = AsCast<OleObjectFrame>(shape);
            if (oleObjectFrame == nullptr)
            {
                continue;
            }

            oleFramesCount++;
            ArrayPtr<uint8_t> embeddedData = oleObjectFrame->get_EmbeddedData()->get_EmbeddedFileData();
            if (embeddedData == nullptr || embeddedData->get_Length() == 0)
            {
                emptyOleFramesCount++;
            }
        }
    }
}

void DeleteEmbeddedBinaryObjects()
{
    //ExStart:DeleteEmbeddedBinaryObjects
    const String pptxFileName = Path::Combine(GetDataPath(), u"OlePptx.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"OlePptx-out.pptx");

    // Create loading options.
    SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();
    loadOptions->set_DeleteEmbeddedBinaryObjects(true);

    // Numbers of frames in a presentation.
    int oleFramesCount;
    // Number of empty frames in a presentation.
    int emptyOleFramesCount;

    SharedPtr<Presentation> pres = MakeObject<Presentation>(pptxFileName, loadOptions);
    GetOleObjectFrameCount(pres->get_Slides(), oleFramesCount, emptyOleFramesCount);

    Console::WriteLine(u"Number of OLE frames in source presentation = {0}", oleFramesCount);
    Console::WriteLine(u"Number of empty OLE frames in source presentation = {0}", emptyOleFramesCount);

    pres->Save(outPath, SaveFormat::Pptx);

    SharedPtr<Presentation> outPres = MakeObject<Presentation>(outPath);
    GetOleObjectFrameCount(outPres->get_Slides(), oleFramesCount, emptyOleFramesCount);

    Console::WriteLine(u"Number of OLE frames in resulting presentation = {0}", oleFramesCount);
    Console::WriteLine(u"Number of empty OLE frames in resulting presentation = {0}", emptyOleFramesCount);

    //ExEnd:DeleteEmbeddedBinaryObjects
}
