#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void ConvertToXml()
{
    //ExStart:ConvertToXml
    const System::String outFilePath = Path::Combine(GetOutPath(), u"example.xml");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
    pres->Save(outFilePath, SaveFormat::Xml);
    //ExEnd:ConvertToXml
}
