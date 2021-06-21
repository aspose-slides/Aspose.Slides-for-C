#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace Xaml;
using namespace System;

class NewXamlSaver : public IXamlOutputSaver
{
    typedef SharedPtr<Collections::Generic::Dictionary<String, String>> Result;

public:
    NewXamlSaver()
        :   m_result(System::MakeObject<Result>())
    {
    }

    Result get_Results()
    {
        return m_result;
    }

    void Save(String path, ArrayPtr<uint8_t> data) override
    {
        String name = IO::Path::GetFileName(path);
        m_result->idx_set(name, Text::Encoding::get_UTF8()->GetString(data));
    }

private:
    Result m_result;
};

void ConvertToXaml()
{
    // Path to source presentation
    String presentationFileName = IO::Path::Combine(GetDataPath(), u"XamlEtalon.pptx");
    
    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationFileName);

    // Create convertion options
    SharedPtr<XamlOptions> xamlOptions = System::MakeObject<XamlOptions>();
    xamlOptions->set_ExportHiddenSlides(true);

    // Define your own output-saving service
    SharedPtr<NewXamlSaver> newXamlSaver = System::MakeObject<NewXamlSaver>();
    xamlOptions->set_OutputSaver(newXamlSaver);

    // Convert slides
    pres->Save(xamlOptions);

    // Save XAML files to an output directory
    for (auto pair : newXamlSaver->get_Results())
    {
        IO::File::AppendAllText(IO::Path::Combine(GetOutPath(), pair.get_Key()), pair.get_Value());
    }
}
