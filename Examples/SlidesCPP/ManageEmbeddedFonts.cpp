#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void ManageEmbeddedFonts()
{
	// ExStart:ManageEmbeddedFonts
	// The path to the documents directory.
	const String outPath = u"../out/ManageEmbeddedFonts_out.pptx";
	const String templatePath = u"../templates/EmbeddedFonts.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// render a slide that contains a text frame that uses embedded "FunSized"
	slide->GetThumbnail(1,1)->Save(u"../out/picture1_out.png", Imaging::ImageFormat::get_Png());

	SharedPtr<IFontsManager> fontsManager = pres->get_FontsManager();

	// get all embedded fonts
	ArrayPtr<SharedPtr<IFontData>>embeddedFonts = fontsManager->GetEmbeddedFonts();
	SharedPtr<IFontData> data = MakeObject<FontData>(u"Calibri");
	SharedPtr<IFontData> funSizedEmbeddedFont = MakeObject<FontData>(u"Calibri");

	// find "Calibri" font
	for (auto font : embeddedFonts)
	{
		if (font->get_FontName() == data->get_FontName())
		{
			funSizedEmbeddedFont = font;
			break;
		}
	}

	// remove "Calibri" font
	fontsManager->RemoveEmbeddedFont(funSizedEmbeddedFont);

	// render the presentation; removed "Calibri" font is replaced to an existing one
	slide->GetThumbnail(1,1)->Save(u"../out/picture2_out.png", Imaging::ImageFormat::get_Png());

	// save the presentation without embedded "Calibri" font
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ManageEmbeddedFonts
}
