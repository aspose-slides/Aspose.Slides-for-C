#ifndef _Examples_Presentations_Conversion_LinkAllFontsHtmlController_h_
#define _Examples_Presentations_Conversion_LinkAllFontsHtmlController_h_

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/array.h>
#include <Export/EmbedAllFontsHtmlController.h>
#include <cstdint>

namespace Aspose { namespace Slides { namespace Export { class IHtmlGenerator; } } }
namespace Aspose { namespace Slides { class IFontData; } }

namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Conversion {

//ExStart:LinkAllFontsHtmlController
class LinkAllFontsHtmlController : public Aspose::Slides::Export::EmbedAllFontsHtmlController
{
    typedef LinkAllFontsHtmlController ThisType;
    typedef Aspose::Slides::Export::EmbedAllFontsHtmlController BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    LinkAllFontsHtmlController(System::ArrayPtr<System::String> fontNameExcludeList, System::String basePath);
    
    virtual void WriteFont(System::SharedPtr<Aspose::Slides::Export::IHtmlGenerator> generator, System::SharedPtr<IFontData> originalFont, System::SharedPtr<IFontData> substitutedFont, System::String fontStyle, System::String fontWeight, System::ArrayPtr<uint8_t> fontData);
    
private:

    System::String m_basePath;
    
};

//  ExEnd:LinkAllFontsHtmlController
} // namespace Conversion
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose

#endif // _Examples_Presentations_Conversion_LinkAllFontsHtmlController_h_

