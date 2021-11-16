#pragma once

#include <DOM/IPresentation.h>
#include <DOM/ISlide.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShape.h>
#include <DOM/IShapeCollection.h>
#include <DOM/SmartArt/ISmartArtShapeCollection.h>

#include <map>

enum class NodeType
{
    unknown,
    presentation,
    slide,
    shape,
    groupShape,
    textBody
};

class PresentationNodeList
{
public:
    PresentationNodeList(System::SharedPtr<Aspose::Slides::IPresentation> presentation);

    Aspose::Slides::IPresentationComponent* getRoot() const;

    NodeType getType(Aspose::Slides::IPresentationComponent* node) const;

    Aspose::Slides::IPresentationComponent* getNode(Aspose::Slides::IPresentationComponent* parent, int index) const;

    Aspose::Slides::IPresentationComponent* getParent(Aspose::Slides::IPresentationComponent* node) const;

    int getIndex(Aspose::Slides::IPresentationComponent* node) const;

    int getChildNodes(Aspose::Slides::IPresentationComponent* node) const;

private:
    void FillNodes(System::SharedPtr<Aspose::Slides::IShapeCollection> shapes);
    void FillNodes(System::SharedPtr<Aspose::Slides::SmartArt::ISmartArtShapeCollection> shapes);

private:
    Aspose::Slides::IPresentationComponent* m_root;
    std::map<Aspose::Slides::IPresentationComponent*, NodeType> m_nodes;
};
