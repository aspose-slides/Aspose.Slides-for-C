QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        $$PWD/../../Source/QtWidgets/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/aspose-slides-cpp-24.4/Aspose.Slides.Cpp/lib/ -lAspose.Slides_vc14x64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/aspose-slides-cpp-24.4/Aspose.Slides.Cpp/lib/ -lAspose.Slides_vc14x64d

INCLUDEPATH += $$PWD/aspose-slides-cpp-24.4/Aspose.Slides.Cpp/include/aspose.slides.cpp
DEPENDPATH += $$PWD/aspose-slides-cpp-24.4/Aspose.Slides.Cpp/include/aspose.slides.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/aspose-slides-cpp-24.4/CodePorting.Translator.Cs2Cpp.Framework/lib/ -lcodeporting.translator.cs2cpp.framework_vc14x64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/aspose-slides-cpp-24.4/CodePorting.Translator.Cs2Cpp.Framework/lib/ -lcodeporting.translator.cs2cpp.framework_vc14x64d

INCLUDEPATH += $$PWD/aspose-slides-cpp-24.4/CodePorting.Translator.Cs2Cpp.Framework/include
DEPENDPATH += $$PWD/aspose-slides-cpp-24.4/CodePorting.Translator.Cs2Cpp.Framework/include
