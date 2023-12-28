#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::Drawing::Imaging;

const System::String templatePath = u"../templates/TestDeck_050.pptx";

void SamplePDF()
{
    try
    {
        auto pres = System::MakeObject<Presentation>(templatePath);

        pres->Save(u"../out/SampleAddText.pdf", SaveFormat::Pdf);
    }
    catch (const System::Exception& e)
    {
        System::Console::WriteLine(u"Running Exports::PDF...");
        System::Console::WriteLine(e->get_Message());
    }
}

void SampleHTML()
{
    try
    {
        auto pres = System::MakeObject<Presentation>(templatePath);

        pres->Save(u"../out/SampleAddText.html", SaveFormat::Html);
    }
    catch (const System::Exception& e)
    {
        System::Console::WriteLine(u"Running Exports::HTML...");
        System::Console::WriteLine(e->get_Message());
    }
}

void SampleXPS()
{
    try
    {
        auto pres = System::MakeObject<Presentation>(templatePath);

        pres->Save(u"../out/SampleAddText.xps", SaveFormat::Xps);
    }
    catch (const System::Exception& e)
    {
        System::Console::WriteLine(u"Running Exports::XPS...");
        System::Console::WriteLine(e->get_Message());
    }
}

void SampleTIFF()
{
    try
    {
        auto pres = System::MakeObject<Presentation>(templatePath);

        pres->Save(u"../out/SampleAddText_Tiff.tiff", SaveFormat::Tiff);

        System::SharedPtr<TiffOptions> tiffOptions = System::MakeObject<TiffOptions>();
        System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
        options->set_NotesPosition(NotesPositions::BottomFull);
        tiffOptions->set_SlidesLayoutOptions(options);

        pres->Save(u"../out/SampleAddText_TiffNotes.tiff", SaveFormat::Tiff, tiffOptions);
    }
    catch (const System::Exception& e)
    {
        System::Console::WriteLine(u"Running Exports::Tiff...");
        System::Console::WriteLine(e->get_Message());
    }
}

void SampleSWF()
{
    try
    { 
        auto pres = System::MakeObject<Presentation>(templatePath);

        pres->Save(u"../out/SampleAddText_Swf.swf", SaveFormat::Swf);

        System::SharedPtr<SwfOptions> swfOptions = System::MakeObject<SwfOptions>();
        System::SharedPtr<INotesCommentsLayoutingOptions> options = swfOptions->get_NotesCommentsLayouting();
        options->set_NotesPosition(NotesPositions::BottomFull);

        pres->Save(u"../out/SampleAddText_SwfNote.swf", SaveFormat::Swf, swfOptions);
    }
    catch (const System::Exception& e)
    {
        System::Console::WriteLine(u"Running Exports::SWF...");
        System::Console::WriteLine(e->get_Message());
    }
}
