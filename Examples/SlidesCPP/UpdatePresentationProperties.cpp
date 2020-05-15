#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void UpdatePresentationProperties()
{
    //ExStart:UpdatePresentationProperties

    const String templatePath = GetDataPath() + u"ModifyBuiltinProperties.pptx";
    const String outPath = GetOutPath() + u"ModifyBuiltinProperties1.pptx";

    if (File::Exists(outPath))
    {
        File::Delete(outPath);
    }

    File::Copy(templatePath, outPath);

    // read the info of presentation 
    SharedPtr<IPresentationInfo> info = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath);

    // obtain the current properties 
    SharedPtr<IDocumentProperties> props = info->ReadDocumentProperties();

    // set the new values of Author and Title fields 
    props->set_Author( u"New Author");
    props->set_Title(u"New Title");

    // update the presentation with a new values 
    info->UpdateDocumentProperties(props);

    info->WriteBindedPresentation(outPath);

    //ExEnd:UpdatePresentationProperties
}