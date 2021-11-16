#include "presentation_node_list.h"
#include <DOM/IAutoShape.h>
#include <DOM/ITextFrame.h>
#include <DOM/IGroupShape.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/SmartArt/ISmartArtNode.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/SmartArt/ISmartArtShape.h>
#include <system/enumerator_adapter.h>

PresentationNodeList::PresentationNodeList(System::SharedPtr<Aspose::Slides::IPresentation> presentation)
{
    m_root = presentation.get();
    m_nodes[m_root] = NodeType::presentation;

    for(const auto& slide : presentation->get_Slides())
    {
        m_nodes[slide.get()] = NodeType::slide;
        FillNodes(slide->get_Shapes());
    }
}

void PresentationNodeList::FillNodes(System::SharedPtr<Aspose::Slides::SmartArt::ISmartArtShapeCollection> shapes)
{
    for(const auto& shape : System::IterateOver(shapes))
    {
        m_nodes[shape.get()] = NodeType::shape;

        if(shape->get_TextFrame() != nullptr &&
          !shape->get_TextFrame()->get_Text().IsEmpty())
        {
            m_nodes[shape->get_TextFrame().get()] = NodeType::textBody;
        }
    }
}

void PresentationNodeList::FillNodes(System::SharedPtr<Aspose::Slides::IShapeCollection> shapes)
{
    for(const auto& shape : shapes)
    {
        auto groupShape = dynamic_cast<Aspose::Slides::IGroupShape*>(shape.get());
        if(groupShape)
        {
            m_nodes[shape.get()] = NodeType::groupShape;
            FillNodes(groupShape->get_Shapes());
        }
        else
        {
            m_nodes[shape.get()] = NodeType::shape;
            auto smartArt = dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(shape.get());
            if(smartArt)
            {
                for(auto smartArtNode : System::IterateOver(smartArt->get_AllNodes()))
                {
                    FillNodes(smartArtNode->get_Shapes());
                }
            }
            else
            {
                auto autoShape = dynamic_cast<Aspose::Slides::IAutoShape*>(shape.get());
                if(autoShape)
                {
                    if(autoShape->get_TextFrame() != nullptr &&
                      !autoShape->get_TextFrame()->get_Text().IsEmpty())
                    {
                        m_nodes[autoShape->get_TextFrame().get()] = NodeType::textBody;
                    }
                }
            }
        }
    }
}

Aspose::Slides::IPresentationComponent *PresentationNodeList::getRoot() const
{
    return m_root;
}

NodeType PresentationNodeList::getType(Aspose::Slides::IPresentationComponent *node) const
{
    auto it = m_nodes.find(node);
    if (it == m_nodes.end())
    {
        return NodeType::unknown;
    }

    return it->second;
}

Aspose::Slides::IPresentationComponent *PresentationNodeList::getNode(Aspose::Slides::IPresentationComponent *parent, int index) const
{
    auto parentType = getType(parent);
    if(parentType == NodeType::presentation)
    {
        auto presentation = dynamic_cast<Aspose::Slides::IPresentation*>(parent);
        if(presentation)
        {
            return presentation->get_Slides()->idx_get(index).get();
        }
    }
    else if(parentType == NodeType::slide)
    {
        auto slide = dynamic_cast<Aspose::Slides::ISlide*>(parent);
        if(slide)
        {
            return slide->get_Shapes()->idx_get(index).get();
        }
    }
    else if(parentType == NodeType::groupShape)
    {
        auto groupShape = dynamic_cast<Aspose::Slides::IGroupShape*>(parent);
        if(groupShape)
        {
            return groupShape->get_Shapes()->idx_get(index).get();
        }
    }
    else if(parentType == NodeType::shape)
    {
        auto autoShape = dynamic_cast<Aspose::Slides::IAutoShape*>(parent);
        if(autoShape)
        {
            if(autoShape->get_TextFrame() != nullptr &&
              !autoShape->get_TextFrame()->get_Text().IsEmpty())
            {
                return autoShape->get_TextFrame().get();
            }
        }

        auto smartArt = dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(parent);
        if(smartArt)
        {
            return smartArt->get_AllNodes()->idx_get(index)->get_Shapes()->idx_get(0).get();
        }

        auto smartArtShape = dynamic_cast<Aspose::Slides::SmartArt::ISmartArtShape*>(parent);
        if(smartArtShape)
        {
            if(smartArtShape->get_TextFrame() != nullptr &&
              !smartArtShape->get_TextFrame()->get_Text().IsEmpty())
            {
                return smartArtShape->get_TextFrame().get();
            }
        }
    }

    return nullptr;
}

Aspose::Slides::IPresentationComponent* FindShapeParent(System::SharedPtr<Aspose::Slides::IShapeCollection> shapes, Aspose::Slides::IShape* shapeForSearch,
                                                             Aspose::Slides::IPresentationComponent* parent)
{
    for(const auto& shape : shapes)
    {
        if(shape.get() == shapeForSearch)
        {
            return parent;
        }

        auto groupShapeFromSlide = dynamic_cast<Aspose::Slides::IGroupShape*>(shape.get());
        if(groupShapeFromSlide)
        {
            auto internalParent = FindShapeParent(groupShapeFromSlide->get_Shapes(), shapeForSearch, groupShapeFromSlide);
            if(internalParent)
            {
                return internalParent;
            }
        }

        auto smartArt = dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(shape.get());
        if(smartArt)
        {
            for(const auto& node : System::IterateOver(smartArt->get_AllNodes()))
            {
                for(const auto& smartArtShape : node->get_Shapes())
                {
                    if(smartArtShape.get() == shapeForSearch)
                    {
                        return smartArt;
                    }
                }
            }
        }
    }

    return nullptr;
}

Aspose::Slides::IPresentationComponent* FindTextFrameParent(System::SharedPtr<Aspose::Slides::IShapeCollection> shapes, Aspose::Slides::ITextFrame* textFrameForSearch)
{
    for(const auto& shape : shapes)
    {
        auto autoShape = dynamic_cast<Aspose::Slides::IAutoShape*>(shape.get());
        if(autoShape)
        {
            if(autoShape->get_TextFrame() != nullptr &&
               autoShape->get_TextFrame().get() == textFrameForSearch)
            {
                return autoShape;
            }
        }

        auto groupShapeFromSlide = dynamic_cast<Aspose::Slides::IGroupShape*>(shape.get());
        if(groupShapeFromSlide)
        {
            auto internalParent = FindTextFrameParent(groupShapeFromSlide->get_Shapes(), textFrameForSearch);
            if(internalParent)
            {
                return internalParent;
            }
        }

        auto smartArt = dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(shape.get());
        if(smartArt)
        {
            for(const auto& node : System::IterateOver(smartArt->get_AllNodes()))
            {
                for(const auto& smartArtShape : node->get_Shapes())
                {
                    if(smartArtShape->get_TextFrame() != nullptr &&
                       smartArtShape->get_TextFrame().get() == textFrameForSearch)
                    {
                        return smartArtShape.get();
                    }
                }
            }
        }
    }

    return nullptr;
}

Aspose::Slides::IPresentationComponent *PresentationNodeList::getParent(Aspose::Slides::IPresentationComponent *node) const
{
    auto type = getType(node);
    if(type == NodeType::presentation)
    {
        return nullptr;
    }
    else if(type == NodeType::slide)
    {
        return m_root;
    }
    else if(type == NodeType::groupShape || type == NodeType::shape)
    {
        auto shape = dynamic_cast<Aspose::Slides::IShape*>(node);
        auto slideComponent = dynamic_cast<Aspose::Slides::ISlideComponent*>(node);
        auto slide = slideComponent->get_Slide();

        return FindShapeParent(slide->get_Shapes(), shape, slide.get());
    }
    else if(type == NodeType::textBody)
    {
        auto textFrame = dynamic_cast<Aspose::Slides::ITextFrame*>(node);
        auto slide = textFrame->get_Slide();
        return FindTextFrameParent(slide->get_Shapes(), textFrame);
    }

    return nullptr;
}

int PresentationNodeList::getIndex(Aspose::Slides::IPresentationComponent *node) const
{
    auto type = getType(node);
    if(type == NodeType::slide)
    {
        auto slide = dynamic_cast<Aspose::Slides::ISlide*>(node);
        return slide->get_SlideNumber() - 1;
    }
    else if(type == NodeType::groupShape || type == NodeType::shape)
    {
        auto shape = dynamic_cast<Aspose::Slides::IShape*>(node);
        auto parent = getParent(shape);

        auto slide = dynamic_cast<Aspose::Slides::ISlide*>(parent);
        if(slide)
        {
            return slide->get_Shapes()->IndexOf(shape);
        }

        auto groupShape = dynamic_cast<Aspose::Slides::IGroupShape*>(parent);
        if(groupShape)
        {
            return groupShape->get_Shapes()->IndexOf(shape);
        }
    }

    return 0;
}
