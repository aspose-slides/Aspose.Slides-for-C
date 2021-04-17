#include <Python.h>
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <iostream>

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

PyObject* convert_to_pdf(PyObject *, PyObject* args)
{
    char* pres_path_py, *pdf_name_py;
    if (!PyArg_ParseTuple(args, "ss", &pres_path_py, &pdf_name_py))
    {
        return nullptr;
    }

    String presentation_name = String::FromAscii(pres_path_py);
    String pdf_name = String::FromAscii(pdf_name_py);

    try
    {
        SharedPtr<Presentation> pres = MakeObject<Presentation>(presentation_name);
        pres->Save(pdf_name, SaveFormat::Pdf);
    }
    catch (Exception ex)
    {
        PyErr_SetString(PyExc_Exception, ex.ToString().ToAsciiString().c_str());
        return nullptr;
    }

    std::cout << "Conversion was successful." << std::endl;
    Py_RETURN_NONE;
}

static PyMethodDef functions[] = 
{
    { "convert_to_pdf", (PyCFunction)convert_to_pdf, METH_VARARGS, nullptr },
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef AsposeSlidesCppExtension_module =
{
    PyModuleDef_HEAD_INIT,
    "AsposeSlidesCppExtension",
    "Provides an example of using Aspose.Slides for C++ in Python",
    0,
    functions
};

PyMODINIT_FUNC PyInit_AsposeSlidesCppExtension()
{
    return PyModule_Create(&AsposeSlidesCppExtension_module);
}
