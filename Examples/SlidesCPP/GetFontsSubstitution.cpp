#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

void GetFontsSubstitution()
{
    //ExStart:GetFontsSubstitution

    const System::String templatePath = u"../templates/PresFontsSubst.pptx";

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    for (auto fontSubstitution : pres->get_FontsManager()->GetSubstitutions())
    {
        System::Console::WriteLine(u"{0} -> {1}", fontSubstitution->get_OriginalFontName(), fontSubstitution->get_SubstitutedFontName());
    }

    //ExEnd:GetFontsSubstitution
}
