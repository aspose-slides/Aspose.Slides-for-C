#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void ExtendedPresentationProperties()
{
    //ExStart:ExtendedPresentationProperties

    // Path for source presentation
    const String pptxFile = Path::Combine(GetDataPath(), u"ExtendDocumentProperies.pptx");
    // Out path
    const String resultPath = Path::Combine(GetOutPath(), u"ExtendDocumentProperies-out1.pptx");

    auto presentation = MakeObject<Presentation>(pptxFile);
    SharedPtr<IDocumentProperties> documentProperties = presentation->get_DocumentProperties();

    // Print the read-only properties
    Console::WriteLine(u"Slides: {0}", documentProperties->get_Slides());
    Console::WriteLine(u"HiddenSlides: {0}", documentProperties->get_HiddenSlides());
    Console::WriteLine(u"Notes: {0}", documentProperties->get_Notes());
    Console::WriteLine(u"Paragraphs: {0}", documentProperties->get_Paragraphs());
    Console::WriteLine(u"MultimediaClips: {0}", documentProperties->get_MultimediaClips());
    Console::WriteLine(u"TitlesOfParts: {0}", String::Join(u"; ", documentProperties->get_TitlesOfParts()));
    Console::WriteLine(u"HeadingPairs: ");
    auto headingPairs = documentProperties->get_HeadingPairs();
    if (headingPairs->get_Length() > 0)
    {
        for (auto&& headingPair : headingPairs)
            Console::WriteLine(u"{0} {1}", headingPair->get_Name(), headingPair->get_Count());
    }

    // Change several boolean properties
    documentProperties->set_ScaleCrop(true);
    documentProperties->set_LinksUpToDate(true);
    documentProperties->set_HyperlinksChanged(true);

    // Save the presentation with changed properties
    presentation->Save(resultPath, SaveFormat::Pptx);

    // Use the IPresentationInfo interface to read and change the document properties
    Console::WriteLine(u"\nProperties obtained by IPresentationInfo:\n");

    SharedPtr<IPresentationInfo> documentInfo = PresentationFactory::get_Instance()->GetPresentationInfo(resultPath);
    documentProperties = documentInfo->ReadDocumentProperties();

    // Print the read-only properties
    Console::WriteLine(u"Slides: {0}", documentProperties->get_Slides());
    Console::WriteLine(u"HiddenSlides: {0}", documentProperties->get_HiddenSlides());
    Console::WriteLine(u"Notes: {0}", documentProperties->get_Notes());
    Console::WriteLine(u"Paragraphs: {0}", documentProperties->get_Paragraphs());
    Console::WriteLine(u"MultimediaClips: {0}", documentProperties->get_MultimediaClips());
    Console::WriteLine(u"TitlesOfParts: {0}", String::Join(u"; ", documentProperties->get_TitlesOfParts()));
    Console::WriteLine(u"HeadingPairs: ");
    headingPairs = documentProperties->get_HeadingPairs();
    if (headingPairs->get_Length() > 0)
    {
        for (auto&& headingPair : headingPairs)
            Console::WriteLine(u"{0} {1}", headingPair->get_Name(), headingPair->get_Count());
    }

    // Change boolean property
    documentProperties->set_HyperlinksChanged(true);

    // Save the presentation with changed properties
    documentInfo->UpdateDocumentProperties(documentProperties);
    documentInfo->WriteBindedPresentation(resultPath);

    //ExEnd:ExtendedPresentationProperties
}
