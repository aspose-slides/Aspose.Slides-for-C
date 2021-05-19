#pragma once
#include "Export/ILinkEmbedController.h"
#include "Export/LinkEmbedDecision.h"

namespace Aspose
{
    namespace Slides
    {
        namespace Examples
        {

/// <summary>
/// This class is responsible for making decisions about the resources saved externally.
/// It must implement the Aspose::Slides::Export::ILinkEmbedController interface.
/// </summary>
class LinkController : public Export::ILinkEmbedController
{
public:
    LinkController();
    LinkController(System::String savePath);

    Export::LinkEmbedDecision GetObjectStoringLocation(int32_t id, System::ArrayPtr<uint8_t> entityData,
                                                       System::String semanticName, System::String contentType,
                                                       System::String recomendedExtension) override;

    System::String GetUrl(int32_t id, int32_t referrer) override;

    void SaveExternal(int32_t id, System::ArrayPtr<uint8_t> entityData) override;

private:
    System::String m_savePath;
    System::SharedPtr<System::Collections::Generic::Dictionary<int32_t, System::String>> m_externalImages;
    static System::SharedPtr<System::Collections::Generic::Dictionary<System::String, System::String>> s_templates;

    static struct __StaticConstructor__
    {
        __StaticConstructor__();
    } s_constructor__;
};

        }
    }
}