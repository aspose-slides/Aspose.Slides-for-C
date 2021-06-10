import platform
from shutil import copy
from distutils.core import setup, Extension

package_name = 'AsposeSlidesCppExtension'

aspose_slides_cpp_folder = ''
if platform.system() == "Windows":
    aspose_slides_cpp_folder = "aspose-slides-cpp-21.6"
else:
    aspose_slides_cpp_folder = "aspose-slides-cpp-linux-21.6"

system_library = aspose_slides_cpp_folder + "/CodePorting.Native.Cs2Cpp"
aspose_slides_cpp = aspose_slides_cpp_folder + "/Aspose.Slides.Cpp"

runtime_library_dirs = []
libraries = []

if platform.system() == 'Windows':
    runtime_library_dirs = []
    libraries = ['Aspose.Slides_vc14x64', 'aspose_cpp_vc14x64']
    copy(aspose_slides_cpp + "/lib/Aspose.Slides_vc14x64.dll", '.')
    copy(system_library + "/lib/aspose_cpp_vc14x64.dll", '.')
else:
    runtime_library_dirs = [system_library + '/lib', aspose_slides_cpp + '/lib']
    libraries = ['Aspose.Slides_clang3_libstdcpp', 'aspose_cpp_clang3_libstdcpp']

copy('../Source/AsposeSlidesCppExtension.cpp', '.')

module = Extension(package_name, 
                    sources = ['AsposeSlidesCppExtension.cpp'],
                    include_dirs=[aspose_slides_cpp + '/include/aspose.slides.cpp', system_library + '/include'],
                    library_dirs = [aspose_slides_cpp + '/lib', system_library + '/lib'],
                    runtime_library_dirs = runtime_library_dirs,
                    libraries = libraries)

setup(name = package_name, version = '1.0',
    description = 'Python package with Aspose.Slides for C++ extension',
    ext_modules = [module])
