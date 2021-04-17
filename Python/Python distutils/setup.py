import platform
from shutil import copy
from distutils.core import setup, Extension

package_name = 'AsposeSlidesCppExtension'

aspose_slides_cpp_folder = ''
runtime_library_dirs = []
libraries = []

if platform.system() == 'Windows':
    aspose_slides_cpp_folder = 'aspose-slides-cpp-21.4'
    runtime_library_dirs = []
    libraries = ['Aspose.Slides_vc14x64', 'aspose_cpp_vc14x64']
    copy(aspose_slides_cpp_folder + "/lib/Aspose.Slides_vc14x64.dll", '.')
    copy(aspose_slides_cpp_folder + "/lib/aspose_cpp_vc14x64.dll", '.')
else:
    aspose_slides_cpp_folder = "aspose-slides-cpp-linux-21.4"
    runtime_library_dirs = [aspose_slides_cpp_folder + '/lib']
    libraries = ['Aspose.Slides_clang3_libstdcpp', 'aspose_cpp_clang3_libstdcpp']

copy('../Source/AsposeSlidesCppExtension.cpp', '.')

module = Extension(package_name, 
                        sources = ['AsposeSlidesCppExtension.cpp'],
                        include_dirs=[aspose_slides_cpp_folder + '/include/aspose.slides.cpp', aspose_slides_cpp_folder + '/include/asposecpplib'],
                        library_dirs = [aspose_slides_cpp_folder + '/lib'],
                        runtime_library_dirs = runtime_library_dirs,
                        libraries = libraries)

setup(name = package_name, version = '1.0',
    description = 'Python package with Aspose.Slides for C++ extension',
    ext_modules = [module])
