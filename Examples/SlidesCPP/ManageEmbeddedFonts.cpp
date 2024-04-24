#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void ManageEmbeddedFonts()
{
    // ExStart:ManageEmbeddedFonts
    // The path to the documents directory.
    const System::String templatePath = Path::Combine(GetDataPath(), u"EmbeddedFonts.pptx");
    const System::String outPath = Path::Combine(GetOutPath(), u"ManageEmbeddedFonts_out.pptx");
    const System::String outPicture1Path = Path::Combine(GetOutPath(), u"picture1_out.png");
    const System::String outPicture2Path = Path::Combine(GetOutPath(), u"picture2_out.png");

    // Load the desired the presentation
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    // Access first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // render a slide that contains a text frame that uses embedded "FunSized"
    System::SharedPtr<IImage> image1 = slide->GetImage(1, 1);
    image1->Save(outPicture1Path, ImageFormat::Png);

    System::SharedPtr<IFontsManager> fontsManager = pres->get_FontsManager();

    // get all embedded fonts
    System::ArrayPtr<System::SharedPtr<IFontData>> embeddedFonts = fontsManager->GetEmbeddedFonts();
    System::SharedPtr<IFontData> data = System::MakeObject<FontData>(u"Calibri");
    System::SharedPtr<IFontData> funSizedEmbeddedFont = System::MakeObject<FontData>(u"Calibri");

    // find "Calibri" font
    for (auto&& font : embeddedFonts)
    {
        if (font->get_FontName() == data->get_FontName())
        {
            funSizedEmbeddedFont = font;
            break;
        }
    }

    // remove "Calibri" font
    fontsManager->RemoveEmbeddedFont(funSizedEmbeddedFont);

    // render the presentation; removed "Calibri" font is replaced to an existing one
    System::SharedPtr<IImage> image2 = slide->GetImage(1, 1);
    image2->Save(outPicture2Path, ImageFormat::Png);

    // save the presentation without embedded "Calibri" font
    pres->Save(outPath, SaveFormat::Pptx);

    // ExEnd:ManageEmbeddedFonts
}
