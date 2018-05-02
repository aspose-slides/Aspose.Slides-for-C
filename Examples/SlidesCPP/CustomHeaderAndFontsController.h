#ifndef _Examples_Presentations_Conversion_CustomHeaderAndFontsController_h_
#define _Examples_Presentations_Conversion_CustomHeaderAndFontsController_h_
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Slides for .NET API reference 
when the project is build. Please check https://docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Slides for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Export/EmbedAllFontsHtmlController.h>

namespace Aspose { namespace Slides { namespace Export { class IHtmlGenerator; } } }
namespace Aspose { namespace Slides { class IPresentation; } }

namespace Aspose {

namespace Slides {

namespace Examples {

namespace CSharp {

namespace Presentations {

namespace Conversion {

//ExStart:CustomHeaderAndFontsController
class CustomHeaderAndFontsController : public Aspose::Slides::Export::EmbedAllFontsHtmlController
{
    typedef CustomHeaderAndFontsController ThisType;
    typedef Aspose::Slides::Export::EmbedAllFontsHtmlController BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    CustomHeaderAndFontsController(System::String cssFileName);
    
    virtual void WriteDocumentStart(System::SharedPtr<Aspose::Slides::Export::IHtmlGenerator> generator, System::SharedPtr<IPresentation> presentation);
    virtual void WriteAllFonts(System::SharedPtr<Aspose::Slides::Export::IHtmlGenerator> generator, System::SharedPtr<IPresentation> presentation);
    
private:

    static const System::String Header;
    System::String m_cssFileName;
    
};

//ExEnd:CustomHeaderAndFontsController
} // namespace Conversion
} // namespace Presentations
} // namespace CSharp
} // namespace Examples
} // namespace Slides
} // namespace Aspose

#endif // _Examples_Presentations_Conversion_CustomHeaderAndFontsController_h_

