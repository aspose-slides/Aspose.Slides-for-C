#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

//ExStart:CopyPortion

SharedPtr<Portion> CopyPortion(SharedPtr<IPortion> por)
{
	SharedPtr<Portion> temp = MakeObject<Portion>();

	//use CreatePortionFormatData!!!
	 SharedPtr<IPortionFormatEffectiveData> portData = por->CreatePortionFormatEffective();

	// use PortionFormat to set values
	temp->get_PortionFormat()->set_AlternativeLanguageId(portData->get_AlternativeLanguageId());
	temp->get_PortionFormat()->set_BookmarkId(portData->get_BookmarkId()) ;
	temp->get_PortionFormat()->set_Escapement(portData->get_Escapement()) ;
	temp->get_PortionFormat()->get_FillFormat()->set_FillType(por->get_PortionFormat()->get_FillFormat()->get_FillType());
	temp->get_PortionFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(portData->get_FillFormat()->get_SolidFillColor()) ;

	temp->get_PortionFormat()->set_FontBold(portData->get_FontBold() ? NullableBool::True : NullableBool::False);
	temp->get_PortionFormat()->set_FontHeight(portData->get_FontHeight());
	temp->get_PortionFormat()->set_FontItalic(portData->get_FontItalic() ? NullableBool::True : NullableBool::False);
	temp->get_PortionFormat()->set_FontUnderline(portData->get_FontUnderline());
	temp->get_PortionFormat()->get_UnderlineFillFormat()->set_FillType(portData->get_UnderlineFillFormat()->get_FillType());
	temp->get_PortionFormat()->get_UnderlineFillFormat()->get_SolidFillColor()->set_Color(portData->get_UnderlineFillFormat()->get_SolidFillColor());
	temp->get_PortionFormat()->set_IsHardUnderlineFill(portData->get_IsHardUnderlineFill() ? NullableBool::True : NullableBool::False);
	temp->get_PortionFormat()->set_IsHardUnderlineLine(portData->get_IsHardUnderlineLine() ? NullableBool::True : NullableBool::False);

	temp->get_PortionFormat()->set_KerningMinimalSize(portData->get_KerningMinimalSize()) ;
	temp->get_PortionFormat()->set_Kumimoji(portData->get_Kumimoji() ? NullableBool::True : NullableBool::False);
	temp->get_PortionFormat()->set_LanguageId(portData->get_LanguageId());

	temp->get_PortionFormat()->set_LatinFont(portData->get_LatinFont()) ;
	temp->get_PortionFormat()->set_EastAsianFont(portData->get_EastAsianFont());
	temp->get_PortionFormat()->set_ComplexScriptFont(portData->get_ComplexScriptFont());
	temp->get_PortionFormat()->set_SymbolFont(portData->get_SymbolFont());

	temp->get_PortionFormat()->set_TextCapType(portData->get_TextCapType());
	temp->get_PortionFormat()->set_Spacing(portData->get_Spacing());
	temp->get_PortionFormat()->set_StrikethroughType(portData->get_StrikethroughType());
	temp->get_PortionFormat()->set_ProofDisabled(portData->get_ProofDisabled() ? NullableBool::True : NullableBool::False);
	temp->get_PortionFormat()->set_NormaliseHeight(portData->get_NormaliseHeight() ? NullableBool::True : NullableBool::False);
	temp->get_PortionFormat()->set_HyperlinkMouseOver(portData->get_HyperlinkMouseOver());
	temp->get_PortionFormat()->set_HyperlinkClick(por->get_PortionFormat()->get_HyperlinkClick());
	temp->get_PortionFormat()->get_HighlightColor()->set_Color(portData->get_HighlightColor());

	return temp;
}
//ExEnd:CopyPortion 