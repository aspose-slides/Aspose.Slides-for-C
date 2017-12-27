#include <Export/SaveFormat.h>
#include <DOM/SmartArt/SmartArtQuickStyleType.h>
#include <DOM/SmartArt/SmartArtNode.h>
#include <DOM/SmartArt/SmartArtLayoutType.h>
#include <DOM/SmartArt/SmartArtColorType.h>
#include <DOM/SmartArt/SmartArt.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/SmartArt/ISmartArtNode.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>

#include "smart_art.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::SmartArt;

using namespace System;

const int NodesCount = 5;
const String outPath = L"../out/";
const String templatePath = L"../templates/SmartArt.pptx";

const String filename1 = IO::Path::Combine(outPath, L"SmartArt.pptx");
const String filename2 = IO::Path::Combine(outPath, L"SmartArt_TextEdit.pptx");
const String filename3 = IO::Path::Combine(outPath, L"SmartArt_NodeAdd.pptx");
const String filename4 = IO::Path::Combine(outPath, L"SmartArt_ColorStyle.pptx");
const String filename5 = IO::Path::Combine(outPath, L"SmartArt_QuickStyle.pptx");
const String filename6 = IO::Path::Combine(outPath, L"SmartArt_NodeRemove.pptx");
const String filename7 = IO::Path::Combine(outPath, L"SmartArt_ArtRemove.pptx");

void SmartAart::SampleCreation()
{
    //create new presentation with SmartArt object
    SharedPtr<Presentation> pres = MakeObject<Presentation>();
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);
    SharedPtr<ISmartArt> smart = slide->get_Shapes()->AddSmartArt(0, 0, 400, 400, SmartArtLayoutType::BasicCycle);

    //saving and reloading presentation
    pres->Save(filename1, Export::SaveFormat::Pptx);
    pres = System::MakeObject<Presentation>(filename1);

    if (pres == nullptr || pres->get_Slides()->get_Count() == 0)
    {
        throw System::ApplicationException(L"Creating error");
    }

    slide = pres->get_Slides()->idx_get(0);
    if (slide->get_Shapes()->get_Count() != 1)
    {
        throw System::ApplicationException(L"Creating error");
    }

    smart = System::DynamicCast<Aspose::Slides::SmartArt::SmartArt>(slide->get_Shapes()->idx_get(0));

    if (smart == nullptr ||
        smart->get_Layout() != SmartArtLayoutType::BasicCycle ||
        smart->get_QuickStyle() != Aspose::Slides::SmartArt::SmartArtQuickStyleType::SimpleFill ||
        smart->get_ColorStyle() != Aspose::Slides::SmartArt::SmartArtColorType::ColoredFillAccent1 ||
        smart->get_AllNodes()->get_Count() != NodesCount)
    {
        throw System::ApplicationException(L"Creating error");
    }
}

void SmartAart::SampleCloning()
{
    //loading presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    //cloning
    SharedPtr<Presentation> clonePres = MakeObject<Presentation>();
    clonePres->get_Slides()->RemoveAt(0);
    clonePres->get_Slides()->AddClone(pres->get_Slides()->idx_get(0));

    // verifying
    auto cloneSmart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(clonePres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    if (cloneSmart == nullptr ||
        cloneSmart->get_AllNodes()->get_Count() != NodesCount ||
        smart->get_Layout() != cloneSmart->get_Layout() ||
        smart->get_QuickStyle() != cloneSmart->get_QuickStyle() ||
        smart->get_ColorStyle() != cloneSmart->get_ColorStyle())
    {
        throw System::ApplicationException(L"Cloning error");
    }
}

void SmartAart::SampleNodesTextEditing()
{
    //loading presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    // modifying nodes
    for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
    {
        SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->idx_get(i);
        node->get_TextFrame()->set_Text(L"TextVerifying");
    }

    pres->Save(filename2, Export::SaveFormat::Pptx);

    //loading result
    pres = MakeObject<Presentation>(filename2);

    //verifying
    if (pres == nullptr ||
        pres->get_Slides()->get_Count() != 1 ||
        pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count() != 1)
    {
        throw System::ApplicationException(L"TextEditing error");
    }

    smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
    if (smart == nullptr ||
        smart->get_Layout() != SmartArtLayoutType::BasicCycle ||
        smart->get_AllNodes()->get_Count() != NodesCount)
    {
        throw System::ApplicationException(L"TextEditing error");
    }

    for (int i = 0; i < smart->get_AllNodes()->get_Count(); i++)
    {
        SharedPtr<ISmartArtNode> node = smart->get_AllNodes()->idx_get(i);
        if (node->get_TextFrame()->get_Text() != L"TextVerifying")
        {
            throw System::ApplicationException(L"TextEditing error");
        }
    }
}

void SmartAart::SampleNodeAdd()
{
    //loading presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    //add child not to existing node
    SharedPtr<ISmartArtNode> exNode = smart->get_AllNodes()->idx_get(0);
    exNode->get_TextFrame()->set_Text(L"parent");

    SharedPtr<ISmartArtNode> chNode = exNode->get_ChildNodes()->AddNode();
    chNode->get_TextFrame()->set_Text(L"child");

    //add new node to root
    SharedPtr<ISmartArtNode> newRootNode = smart->get_AllNodes()->AddNode();
    newRootNode->get_TextFrame()->set_Text(L"newRootNode");

    SharedPtr<ISmartArtNode> newRootNodeChild = newRootNode->get_ChildNodes()->AddNode();
    newRootNodeChild->get_TextFrame()->set_Text(L"newRootNodeChild");

    pres->Save(filename3, Export::SaveFormat::Pptx);

    //loading result
    pres = MakeObject<Presentation>(filename3);

    if (pres == nullptr ||
        pres->get_Slides()->get_Count() != 1 ||
        pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count() != 1)
    {
        throw System::ApplicationException(L"NodeAdd error");
    }

    smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    if (smart == nullptr ||
        smart->get_Layout() != SmartArtLayoutType::BasicCycle ||
        smart->get_AllNodes()->get_Count() != NodesCount + 3)
    {
        throw System::ApplicationException(L"NodeAdd error");
    }

    //verifying
    for (int i = 1; i < smart->get_AllNodes()->get_Count(); i++)
    {
        SharedPtr<ISmartArtNode> testNode = smart->get_AllNodes()->idx_get(i);

        if (testNode == nullptr)
        {
            throw System::ApplicationException(L"NodeAdd error");
        }

        if (testNode->get_TextFrame()->get_Text() == L"parent" ||
            testNode->get_TextFrame()->get_Text() == L"newRootNode")
        {
            SharedPtr<SmartArtNode> foundChild;
            auto enumerator_0 = (DynamicCastEnumerableTo<SharedPtr<SmartArtNode>>(testNode->get_ChildNodes()))->GetEnumerator();
            decltype(enumerator_0->get_Current()) node_0;
            while (enumerator_0->MoveNext() && (node_0 = enumerator_0->get_Current(), true))
            {
                if (node_0->get_TextFrame() == nullptr)
                {
                    throw System::ApplicationException(L"NodeAdd error");
                }

                if ((node_0->get_TextFrame()->get_Text() == L"child" && testNode->get_TextFrame()->get_Text() == L"parent") ||
                    (node_0->get_TextFrame()->get_Text() == L"newRootNodeChild" && testNode->get_TextFrame()->get_Text() == L"newRootNode"))
                {
                    foundChild = node_0;
                    break;
                }
            }
            if (foundChild == nullptr)
            {
                throw System::ApplicationException(L"NodeAdd error");
            }
        }
    }
}

void SmartAart::SampleColorStyleEditing()
{
    //loading presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    //reassign style
    SmartArtColorType newStyle = SmartArtColorType::GradientLoopAccent1;
    smart->set_ColorStyle(newStyle);

    pres->Save(filename4, Export::SaveFormat::Pptx);

    //loading, verifying
    pres = MakeObject<Presentation>(filename4);

    if (pres == nullptr ||
        pres->get_Slides()->get_Count() != 1 ||
        pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count() != 1)
    {
        throw System::ApplicationException(L"ColorStyleEditing error");
    }

    smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    if (smart == nullptr ||
        smart->get_Layout() != SmartArtLayoutType::BasicCycle ||
        smart->get_ColorStyle() != newStyle)
    {
        throw System::ApplicationException(L"ColorStyleEditing error");
    }
}

void SmartAart::SampleQuickStyleEditing()
{
    //loading presentation
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    //reassign style
    SmartArtQuickStyleType newStyle = SmartArtQuickStyleType::FlatScene;
    smart->set_QuickStyle(newStyle);

    pres->Save(filename5, Export::SaveFormat::Pptx);

    //loading, verifying
    pres = MakeObject<Presentation>(filename5);

    if (pres == nullptr ||
        pres->get_Slides()->get_Count() != 1 ||
        pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count() != 1)
    {
        throw System::ApplicationException(L"QuickStyleEditing error");
    }

    smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    if (smart == nullptr ||
        smart->get_Layout() != SmartArtLayoutType::BasicCycle ||
        smart->get_QuickStyle() != newStyle)
    {
        throw System::ApplicationException(L"QuickStyleEditing error");
    }
}

void SmartAart::SampleNodeRemove()
{
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
    smart->get_AllNodes()->RemoveNode(0);

    pres->Save(filename6, Export::SaveFormat::Pptx);

    pres = MakeObject<Presentation>(filename6);

    if (pres == nullptr ||
        pres->get_Slides()->get_Count() != 1 ||
        pres->get_Slides()->idx_get(0)->get_Shapes()->get_Count() != 1)
    {
        throw System::ApplicationException(L"NodeRemove error");
    }

    smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    if (smart == nullptr ||
        smart->get_AllNodes()->get_Count() != NodesCount - 1)
    {
        throw System::ApplicationException(L"NodeRemove error");
    }
}

void SmartAart::SampleRemoveSmartArt()
{
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    auto smart = DynamicCast<Aspose::Slides::SmartArt::SmartArt>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));

    pres->get_Slides()->idx_get(0)->get_Shapes()->Remove(smart);
    pres->Save(filename7, Export::SaveFormat::Pptx);

    pres = MakeObject<Presentation>(filename7);

    if (pres == nullptr ||
        pres->get_Slides()->get_Count() != 1)
    {
        throw System::ApplicationException(L"RemoveSmartArt error");
    }

    auto enumerator_1 = (DynamicCastEnumerableTo<SharedPtr<Shape>>(pres->get_Slides()->idx_get(0)->get_Shapes()))->GetEnumerator();
    decltype(enumerator_1->get_Current()) shape_1;
    while (enumerator_1->MoveNext() && (shape_1 = enumerator_1->get_Current(), true))
    {
        if (ObjectExt::Is<Aspose::Slides::SmartArt::SmartArt>(shape_1))
        {
            throw System::ApplicationException(L"RemoveSmartArt error");
        }
    }
}
