/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Slides for .NET API reference 
when the project is build. Please check https://docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Slides for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/
#include "stdafx.h"
#include "CustomHeaderAndFontsController.h"

using namespace Aspose::Slides::Export;
namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Presentations {

namespace Conversion {

RTTI_INFO_IMPL_HASH(313786785u, ::Aspose::Slides::Examples::CSharp::Presentations::Conversion::CustomHeaderAndFontsController, ThisTypeBaseTypesInfo);

const System::String CustomHeaderAndFontsController::Header = System::String(u"<!DOCTYPE html>\n") + u"<html>\n" + u"<head>\n" + u"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n" + u"<meta http-equiv=\"X-UA-Compatible\" content=\"IE=9\">\n" + u"<link rel=\"stylesheet\" type=\"text/css\" href=\"{0}\">\n" + u"</head>";

CustomHeaderAndFontsController::CustomHeaderAndFontsController(System::String cssFileName)
{
    m_cssFileName = cssFileName;
}

void CustomHeaderAndFontsController::WriteDocumentStart(System::SharedPtr<Aspose::Slides::Export::IHtmlGenerator> generator, System::SharedPtr<IPresentation> presentation)
{
    generator->AddHtml(System::String::Format(Header,m_cssFileName));
    WriteAllFonts(generator, presentation);
}

void CustomHeaderAndFontsController::WriteAllFonts(System::SharedPtr<Aspose::Slides::Export::IHtmlGenerator> generator, System::SharedPtr<IPresentation> presentation)
{
    generator->AddHtml(u"<!-- Embedded fonts -->");
    EmbedAllFontsHtmlController::WriteAllFonts(generator, presentation);
}

} // namespace Conversion
} // namespace Presentations
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose
