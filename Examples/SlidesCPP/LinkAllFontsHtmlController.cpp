#include "LinkAllFontsHtmlController.h"

#include <system/string.h>
#include <system/io/path.h>
#include <system/io/file.h>
#include <system/array.h>
#include <Export/IHtmlGenerator.h>
#include <Export/EmbedAllFontsHtmlController.h>
#include <DOM/IFontData.h>
#include <cstdint>


using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Conversion {

RTTI_INFO_IMPL_HASH(278374607u, ::Aspose::Slides::Examples::CSharp::Conversion::LinkAllFontsHtmlController, ThisTypeBaseTypesInfo);

LinkAllFontsHtmlController::LinkAllFontsHtmlController(System::ArrayPtr<System::String> fontNameExcludeList, System::String basePath)
     : Aspose::Slides::Export::EmbedAllFontsHtmlController(fontNameExcludeList)
{
    m_basePath = basePath;
}

void LinkAllFontsHtmlController::WriteFont(System::SharedPtr<Aspose::Slides::Export::IHtmlGenerator> generator, System::SharedPtr<IFontData> originalFont, System::SharedPtr<IFontData> substitutedFont, System::String fontStyle, System::String fontWeight, System::ArrayPtr<uint8_t> fontData)
{
    System::String fontName = substitutedFont == nullptr ? originalFont->get_FontName() : substitutedFont->get_FontName();
    System::String path = System::String::Format(u"{0}.woff",fontName);
    // some path sanitaze may be needed
    System::IO::File::WriteAllBytes(System::IO::Path::Combine(m_basePath, path), fontData);
    
    generator->AddHtml(u"<style>");
    generator->AddHtml(u"@font-face { ");
    generator->AddHtml(System::String::Format(u"font-family: '{0}'; ",fontName));
    generator->AddHtml(System::String::Format(u"src: url('{0}')",path));
    
    generator->AddHtml(u" }");
    generator->AddHtml(u"</style>");
}

} // namespace Conversion
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose
