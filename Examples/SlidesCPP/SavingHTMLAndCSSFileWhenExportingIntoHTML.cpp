/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Slides for .NET API reference 
when the project is build. Please check https://docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Slides for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/
#include "SavingHTMLAndCSSFileWhenExportingIntoHTML.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include <Export/HtmlFormatter.h>
#include <DOM/Presentation.h>

#include "SlidesExamples.h"
#include "CustomHeaderAndFontsController.h"


using namespace Aspose::Slides::Export;
namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Presentations {

namespace Conversion {

RTTI_INFO_IMPL_HASH(2467631320u, ::Aspose::Slides::Examples::CSharp::Presentations::Conversion::SavingHTMLAndCSSFileWhenExportingIntoHTML, ThisTypeBaseTypesInfo);

void SavingHTMLAndCSSFileWhenExportingIntoHTML::Run()
{
    //ExStart:SavingHTMLAndCSSFileWhenExportingIntoHTML
    // The path to the documents directory.
 	const String outPath = u"../out/HTMLAndCSSFileWhenExportingIntoHTML_out.svg";
	const String templatePath = u"../templates/AccessSlides.pptx";

	{
        System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
        
        // Clearing resources under 'using' statement
       // System::Details::DisposeGuard __dispose_guard_0{ pres, ASPOSE_CURRENT_FUNCTION };
        // ------------------------------------------
        System::SharedPtr<CustomHeaderAndFontsController> htmlController = System::MakeObject<CustomHeaderAndFontsController>(u"styles.css");
        System::SharedPtr<HtmlOptions> options = [&]{ auto tmp_0 = System::MakeObject<HtmlOptions>(); tmp_0->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(htmlController)); return tmp_0; }();
        
        pres->Save(u"pres.html", Aspose::Slides::Export::SaveFormat::Html, options);
		
		//ExEnd:SavingHTMLAndCSSFileWhenExportingIntoHTML

    }
}

} // namespace Conversion
} // namespace Presentations
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose
  /*
  This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Slides for .NET API reference
  when the project is build. Please check https://docs.nuget.org/consume/nuget-faq for more information.
  If you do not wish to use NuGet, you can manually download Aspose.Slides for .NET API from http://www.aspose.com/downloads,
  install it and then add its reference to this project. For any issues, questions or suggestions
  please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
  */
/*
#include "SavingHTMLAndCSSFileWhenExportingIntoHTML.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include <Export/HtmlFormatter.h>
#include <DOM/Presentation.h>

#include "SlidesExamples.h"
#include "CustomHeaderAndFontsController.h"


using namespace Aspose::Slides::Export;
namespace Aspose {

	namespace Slides {

		namespace Examples {

			namespace CSharp {

				namespace Presentations {

					namespace Conversion {

						RTTI_INFO_IMPL_HASH(2467631320u, ::Aspose::Slides::Examples::CSharp::Presentations::Conversion::SavingHTMLAndCSSFileWhenExportingIntoHTML, ThisTypeBaseTypesInfo);

						void SavingHTMLAndCSSFileWhenExportingIntoHTML::Run()
						{
							//ExStart:SavingHTMLAndCSSFileWhenExportingIntoHTML
							// The path to the documents directory.
							const String outPath = u"../out/SavingHTMLAndCSSFileWhenExportingIntoHTML_out.hmtl";
							const String templatePath = u"../templates/AccessSlides.pptx";

							{
								System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

								// Clearing resources under 'using' statement
								System::Details::DisposeGuard __dispose_guard_0{ pres, ASPOSE_CURRENT_FUNCTION };
								// ------------------------------------------
								System::SharedPtr<CustomHeaderAndFontsController> htmlController = System::MakeObject<CustomHeaderAndFontsController>(u"styles.css");
								System::SharedPtr<HtmlOptions> options = [&] { auto tmp_0 = System::MakeObject<HtmlOptions>(); tmp_0->set_HtmlFormatter(HtmlFormatter::CreateCustomFormatter(htmlController)); return tmp_0; }();

								pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Html, options);
							}
						}

					} // namespace Conversion
				} // namespace Presentations
			} // namespace CSharp
		} // namespace Examples
	} // namespace Slides
} // namespace Aspose
*/