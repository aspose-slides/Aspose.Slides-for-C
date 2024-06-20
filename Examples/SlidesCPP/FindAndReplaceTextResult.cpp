#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace Collections::Generic;
using namespace IO;

struct WordInfo
{
    WordInfo() = default;

    WordInfo(const SharedPtr<ITextFrame>& textFrame, const String sourceText, const String foundText, int32_t textPosition)
        : TextFrame(textFrame), SourceText(sourceText), FoundText(foundText), TextPosition(textPosition)
    {}

    SharedPtr<ITextFrame> TextFrame;
    String SourceText;
    String FoundText;
    int32_t TextPosition;
};

// Class that provides information about all found occurrences of a given text.
class FindResultCallback : public IFindResultCallback
{
public:
    FindResultCallback()
        : m_words(MakeObject<List<WordInfo>>())
    {}

    // Array of retrieved text information.
    ArrayPtr<WordInfo> GetWords()
    {
        return m_words->ToArray();
    }

    // The number of matches found to a given text.
    int32_t GetCount()
    {
        return m_words->get_Count();
    }

    // Gets all slides in which the given text was found.
    ArrayPtr<int32_t> GetSlideNumbers()
    {
        auto slideNumbers = MakeObject<List<int32_t>>();
        for (auto&& element : m_words)
        {
            int32_t slideNumber = System::ExplicitCast<Slide>(element.TextFrame->get_Slide())->get_SlideNumber();
            if (!slideNumbers->Contains(slideNumber))
            {
                slideNumbers->Add(slideNumber);
            }
        }

        return slideNumbers->ToArray();
    }

    // Gets all occurrences of the found text on the slide.
    ArrayPtr<WordInfo> GetElementsForSlide(int32_t slideNumber)
    {
        auto foundElements = MakeObject<List<WordInfo>>();
        for (auto&& element : m_words)
        {
            int32_t elementSlideNumber = System::ExplicitCast<Slide>(element.TextFrame->get_Slide())->get_SlideNumber();
            if (elementSlideNumber == slideNumber)
            {
                foundElements->Add(element);
            }
        }

        return foundElements->ToArray();
    }

    // Callback method that receives data about the found text.
    void FoundResult(SharedPtr<ITextFrame> textFrame, String sourceText, String foundText, int32_t textPosition) override
    {
        m_words->Add(WordInfo(textFrame, sourceText, foundText, textPosition));
    }

private:
    SharedPtr<List<WordInfo>> m_words;
};

void FindAndReplaceTextResult()
{
    //ExStart:FindAndReplaceTextResult
    const String dataPath = Path::Combine(GetDataPath(), u"TextReplaceExample.pptx");
    const String outPath = Path::Combine(GetOutPath(), u"TextReplaceExampleReplace-out.pptx");

    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(dataPath);

    auto callback = MakeObject<FindResultCallback>();
    presentation->ReplaceText(u"[this block]", u"my text", MakeObject<TextSearchOptions>(), callback);

    Console::WriteLine(u"Number of found fragments = {0}", callback->GetCount());

    for (auto&& wordInfo : callback->GetWords())
    {
        Console::WriteLine(u"Text = {0}, Position = {1}", wordInfo.FoundText, wordInfo.TextPosition);
    }

    presentation->Save(outPath, SaveFormat::Pptx);
    //ExEnd:FindAndReplaceTextResult
}
