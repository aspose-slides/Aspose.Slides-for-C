/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Slides for .NET API reference 
when the project is build. Please check https://docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Slides for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/
#include "ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <system/array.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include <Export/HtmlFormatter.h>
#include <Export/EmbedAllFontsHtmlController.h>
#include <DOM/Presentation.h>
#include <DOM/Paragraph.h>
#include <DOM/ITextFrame.h>
#include "LinkAllFontsHtmlController.h"

//#include "SlidesExamples.h"


using namespace Aspose::Slides::Export;
using namespace Aspose::Slides::Examples::CSharp::Conversion;
using namespace System;
namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Presentations {

namespace Conversion {

RTTI_INFO_IMPL_HASH(1623090068u, ::Aspose::Slides::Examples::CSharp::Presentations::Conversion::ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController, ThisTypeBaseTypesInfo);

void ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController::Run()
{
    //ExStart:ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController
	const String outPath = u"../out/PresentationToHtmlWithEmbedAllFontsHtmlController_out.hmtl";
	const String templatePath = u"../templates/AccessSlides.pptx";
	{
        System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
        
        // Clearing resources under 'using' statement
        //System::Details::DisposeGuard __dispose_guard_0{ pres, ASPOSE_CURRENT_FUNCTION };
        // ------------------------------------------
        // exclude default presentation fonts
        System::ArrayPtr<System::String> fontNameExcludeList = System::MakeArray<System::String>({u"Calibri", u"Arial"});
        
        
        System::SharedPtr<Paragraph> para = System::MakeObject<Paragraph>();
        System::SharedPtr<ITextFrame> txt;
        
        System::SharedPtr<EmbedAllFontsHtmlController> embedFontsController = System::MakeObject<EmbedAllFontsHtmlController>(fontNameExcludeList);
        
        System::SharedPtr<LinkAllFontsHtmlController> linkcont = System::MakeObject<LinkAllFontsHtmlController>(fontNameExcludeList, u"C:\\Windows\\Fonts\\");
        
        System::SharedPtr<HtmlOptions> htmlOptionsEmbed = [&]{ auto tmp_0 = System::MakeObject<HtmlOptions>(); tmp_0->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(linkcont)); return tmp_0; }();
        
        pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Html, htmlOptionsEmbed);
        //ExEnd:ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController
    }
}

} // namespace Conversion
} // namespace Presentations
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose
