#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void SensitivityLabelsExample()
{
    //ExStart:SensitivityLabelsExample

    // The example below demonstrates how to check a password to open a presentation
    const String pptxFile = Path::Combine(GetDataPath(), u"OldSensitivitiLabels.pptx");

    // Out path
    const String outPath = Path::Combine(GetOutPath(), u"SensitivitiLabels_out.pptx");

    const String labelId = u"{0372a796-4aa3-4c41-9a98-8232cac474f6}";
    const String labelId2 = u"{c0c0bc41-48d8-4bf2-a038-8ec8c93813b5}";
    Guid siteId = Guid(u"{c336d4c6-89ce-480c-beb0-3bfa5538f186}");

    auto pres = MakeObject<Presentation>(pptxFile);

    // Get sensitivity labels from the custom document properties
    auto mipSensitivityLabels = pres->get_DocumentProperties()->GetSensitivityLabels();

    auto sensitivityLabels = pres->get_SensitivityLabels();
    for (auto&& sensitivityLabel : mipSensitivityLabels)
    {
        // Add label to the collection
        sensitivityLabels->Add(sensitivityLabel);
    }

    // Add sensitivity labels
    auto label1 = sensitivityLabels->Add(labelId, siteId, true, SensitivityLabelAssignmentType::Standard);
    label1->get_ContentMarkTypes()->Add(SensitivityLabelContentType::Header);
    label1->set_IsRemoved(true);

    auto label2 = sensitivityLabels->Add(labelId2, siteId, true, SensitivityLabelAssignmentType::Privileged);
    label2->get_ContentMarkTypes()->Add(SensitivityLabelContentType::Footer);
    label2->get_ContentMarkTypes()->Add(SensitivityLabelContentType::Watermark);

    // Print sensitivity labels
    for (auto&& sensitivityLabel : sensitivityLabels)
    {
        Console::WriteLine(u"Label ID {0} from site {1}", sensitivityLabel->get_Id(), sensitivityLabel->get_SiteId());
    }

    pres->Save(outPath, SaveFormat::Pptx);

    //ExEnd:SensitivityLabelsExample
}
