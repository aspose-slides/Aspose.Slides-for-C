![Nuget](https://img.shields.io/nuget/v/Aspose.slides.Cpp) ![Nuget](https://img.shields.io/nuget/dt/Aspose.slides.Cpp)
# C++ Class Library for PowerPoint Files

[Aspose.Slides for C++](https://products.aspose.com/slides/cpp) is a presentation file formats processing library that enables the C++ applications to manipulate, render and convert Microsoft PowerPoint® presentations without requiring Microsoft PowerPoint application. Aspose.Slides for C++ supports most of the Microsoft PowerPoint presentation and slideshow file formats including PPT, POT, PPS, PPTX, POTX, PPSX and ODP.

<p align="center">

  <a title="Download complete Aspose.Slides for C++ source code" href="https://github.com/aspose-slides/Aspose.Slides-for-C/archive/master.zip">
	<img src="https://raw.github.com/AsposeExamples/java-examples-dashboard/master/images/downloadZip-Button-Large.png" />
  </a>
</p>

Directory | Description
--------- | -----------
[Examples](Examples)  | A collection of C++ examples that help you learn the product features
[Nodejs](Nodejs)  | Demo examples of using Aspose.Slides for C++ in Node.js
[PHP](PHP)  | Demo examples of using Aspose.Slides for C++ in PHP
[Python](Python)  | Demo examples of using Aspose.Slides for C++ in Python
[QtDemos](QtDemos)  | Demo examples of using Aspose.Slides for C++ in Qt applications

## Presentation Processing via C++

Checkout the [product overview](https://docs.aspose.com/slides/cpp/product-overview/) to know all about Aspose.Slides for C++.

- Create, open and manipulate presentations without Microsoft PowerPoint.
- [Convert presentations](https://docs.aspose.com/slides/cpp/converting-a-presentation/) to any of the [supported file formats](https://docs.aspose.com/slides/cpp/supported-file-formats/).
- High fidelity rendering of slides to various graphics formats.
- Access, modify or create almost all the possible contents of the presentation.
- Format text and shapes on slides in a presentation.
- Load protected presentations or control access to presentations, slides or objects via advanced security features.


## Read & Write PowerPoint Files

**Microsoft PowerPoint:** PPT, POT, PPS, PPTX, POTX, PPSX, PPTM, PPSM, POTM\
**OpenOffice:** ODP, FODP\
**Open Document:** OTP\
**Other:** TIFF, EMF, XML

## Save Presentation As

**Fixed Layout:** PDF, PDF/A, XPS\
**Images:** JPEG, PNG, GIF, BMP, SVG\
**Web:** HTML

## Platform Independence

Aspose.Slides for C++ is a native C++ library that supports 64-bit operating systems, such as, Windows (XP and onward) & Linux (Ubuntu 16.04 or later). The supported platforms include Windows (Microsoft Visual C++)  & Linux (Clang).

## Get Started with Aspose.Slides for C++

Let's give Aspose.Slides for C++ a try! Simply execute `Install-Package Aspose.Slides.Cpp` from Package Manager Console in Visual Studio to fetch the NuGet package. If you already have Aspose.Slides for C++ and want to upgrade the version, please execute `Update-Package Aspose.Slides.Cpp` to get the latest version.

## Create PPTX Presentation from scratch

```c++
// instantiate Presentation class that represents PPTX file
SharedPtr<Presentation> pres = MakeObject<Presentation>();
SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

// add an autoshape of type line
slide->get_Shapes()->AddAutoShape(Aspose::Slides::ShapeType::Line, 50.0, 150.0, 300.0, 0.0);
// save presentation
pres->Save(u"output.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
```

## Convert PPTX to PDF using C++

```c++
// instantiate Presentation class
SharedPtr<Presentation> pres = MakeObject<Presentation>(u"template.pptx");
// save the loaded presentation in PDF format
pres->Save(u"output.pdf", Aspose::Slides::Export::SaveFormat::Pdf);
```

[Home](https://www.aspose.com/) | [Product Page](https://products.aspose.com/slides/cpp) | [Docs](https://docs.aspose.com/slides/cpp/) | [Demos](https://products.aspose.app/slides/family) | [API Reference](https://apireference.aspose.com/slides/cpp) | [Examples](https://github.com/aspose-slides/Aspose.Slides-for-C) | [Blog](https://blog.aspose.com/category/slides/) | [Free Support](https://forum.aspose.com/c/slides) | [Temporary License](https://purchase.aspose.com/temporary-license)
