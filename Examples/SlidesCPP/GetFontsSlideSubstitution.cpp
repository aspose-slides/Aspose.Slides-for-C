#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void GetFontsSlideSubstitution()
{
    //ExStart:GetFontsSlideSubstitution

    const String pptxPath = Path::Combine(GetDataPath(), u"PresFontsSubst.pptx");

    auto pres = System::MakeObject<Presentation>(pptxPath);

    for (auto fontSubstitution : pres->get_FontsManager()->GetSubstitutions(MakeArray<int>({ 1, 2 })))
    {
        Console::WriteLine(u"{0} -> {1}", fontSubstitution->get_OriginalFontName(), fontSubstitution->get_SubstitutedFontName());
    }

    //ExEnd:GetFontsSlideSubstitution
}
