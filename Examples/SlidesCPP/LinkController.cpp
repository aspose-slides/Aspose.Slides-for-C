#include "stdafx.h"
#include "LinkController.h"
#include <system/collections/dictionary.h>

using namespace System;
using namespace Collections::Generic;
using namespace Aspose::Slides;
using namespace Export;
using namespace Examples;

SharedPtr<Dictionary<String, String>> LinkController::s_templates = System::MakeObject<Dictionary<String, String>>();
LinkController::__StaticConstructor__ LinkController::s_constructor__;

LinkController::__StaticConstructor__::__StaticConstructor__()
{
    s_templates->Add(u"image/jpeg", u"image-{0}.jpg");
    s_templates->Add(u"image/png", u"image-{0}.png");
}

LinkController::LinkController()
{
    m_externalImages = System::MakeObject<Dictionary<int32_t, String>>();
}

LinkController::LinkController(System::String savePath): LinkController()
{
    m_savePath = savePath;
}

LinkEmbedDecision LinkController::GetObjectStoringLocation(int32_t id, ArrayPtr<uint8_t> entityData,
                                                            String semanticName, String contentType,
                                                            String recomendedExtension)
{
    // Here we make the decision about storing images externally.
    // The id is unique identifier of each object during the whole export operation.

    String template_;

    // The s_templates dictionary contains content types we are going to store externally and the corresponding file name template.
    if (s_templates->TryGetValue(contentType, template_))
    {
        // Storing this resource to the export list
        m_externalImages->Add(id, template_);
        return LinkEmbedDecision::Link;
    }

    // All other resources, if any, will be embedded
    return LinkEmbedDecision::Embed;
}

String LinkController::GetUrl(int32_t id, int32_t referrer)
{
    // Here we construct the resource reference string to form the tag: <img src="%result%">
    // We need to check the dictionary to filter out unnecessary resources.
    // Along with checking we extract the corresponding file name template.
    String template_;
    if (m_externalImages->TryGetValue(id, template_))
    {
        // Assuming we are going to store resource files just near the HTML file.
        // The image tag will look like <img src="image-1.png"> with the appropriate resource Id and extension.
        String fileUrl = String::Format(template_, id);
        return fileUrl;
    }

    // null must be returned for the resources remaining embedded
    return nullptr;
}

void LinkController::SaveExternal(int32_t id, System::ArrayPtr<uint8_t> entityData)
{
    // Here we actually save the resource files to disk.
    // Once again, checking the dictionary. If the id is not found here it is a sign of an error in GetObjectStoringLocation or GetUrl methods.
    if (m_externalImages->ContainsKey(id))
    {
        // Now we use the file name stored in the dictionary and combine it with a path as required.

        // Constructing the file name using the stored template and the Id.
        String fileName = String::Format(m_externalImages->idx_get(id), id);

        // Combining with the location directory
        const String savePath = m_savePath != nullptr ? m_savePath : String::Empty;
        String filePath = IO::Path::Combine(savePath, fileName);

        auto fs = System::MakeObject<IO::FileStream>(filePath, IO::FileMode::Create);
        fs->Write(entityData, 0, entityData->get_Length());
    }
    else
    {
        throw Exception(u"Something is wrong");
    }
}
