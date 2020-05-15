#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetFontsFolders()
{
	// ExStart:GetFontsFolders
	// The path to the documents directory.

	//The following line shall return folders where font files are searched.
	//Those are folders that have been added with LoadExternalFonts method as well as system font folders.
	ArrayPtr<String> fontFolders = FontsLoader::GetFontFolders();

	// ExEnd:GetFontsFolders
}
