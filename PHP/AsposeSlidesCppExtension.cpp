#include "php.h"
#include "ext/standard/info.h"
#include "zend_exceptions.h"
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <Util/License.h>
#include <iostream>

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

PHP_FUNCTION(convert_to_pdf) {
    char *str = 0;
    size_t str_len = 0;
    char *str2 = 0;
    size_t str_len2 = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STRING(str, str_len)
        Z_PARAM_STRING(str2, str_len2)
    ZEND_PARSE_PARAMETERS_END();

    std::string pres_path_php(str, str_len);
    std::string pdf_name_php(str2, str_len2);
    
    String presentation_name = String::FromAscii(pres_path_php);
    String pdf_name = String::FromAscii(pdf_name_php);

    try
    {
        SharedPtr<Presentation> pres = MakeObject<Presentation>(presentation_name);
        pres->Save(pdf_name, SaveFormat::Pdf);
    }
    catch (Exception ex)
    {
        zend_throw_exception(zend_ce_exception, ex.ToString().ToAsciiString().c_str(), 0);
    }
}

static const zend_function_entry AsposeSlidesCppExtension_functions[] = {
    PHP_FE(convert_to_pdf, NULL)
    PHP_FE_END
};

static PHP_MINIT_FUNCTION(AsposeSlidesCppExtension_init);

zend_module_entry AsposeSlidesCppExtension_module_entry = {
    STANDARD_MODULE_HEADER,
    "AsposeSlidesCppExtension",
    AsposeSlidesCppExtension_functions,
    PHP_MINIT(AsposeSlidesCppExtension_init),
    NULL,
    NULL,
    NULL,
    NULL,
    "1.0.0",
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(AsposeSlidesCppExtension)

static PHP_MINIT_FUNCTION(AsposeSlidesCppExtension_init)
{
    zval val;
    ZVAL_STRING(&val, "aspose_slides_cpp_license");
    auto v = cfg_get_entry_ex(Z_STR(val));
    convert_to_string(v);
    std::string licensePath(Z_STRVAL(*v));

    if (licensePath.length() == 0)
    {
        return SUCCESS;
    }

    char buffer[1024];
    String licFile = String::FromUtf8(licensePath.c_str());
    try
    {
        SharedPtr<License> lic = MakeObject<License>();
        lic->SetLicense(licFile);

        if (lic->IsLicensed())
        {
            snprintf(buffer, 1024, "Aspose.Slides for C++ license has been applied");
        }
        else
        {
            snprintf(buffer, 1024, "Warning: License is not properly applied or is expired");
        }
    }
    catch (Exception ex)
    {
        snprintf(buffer, 1024, "Failed to load Aspose.Slides for C++ license from file %s: %s", licensePath.c_str(),  ex.ToString().ToAsciiString().c_str());
    }
       
    php_error(E_WARNING, buffer);
       
    return SUCCESS;
}
