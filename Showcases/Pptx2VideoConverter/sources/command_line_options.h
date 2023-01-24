#ifndef COMMAND_LINE_OPTIONS_H
#define COMMAND_LINE_OPTIONS_H

#include <cstdint>

#include <system/string.h>

struct CommandLineOptions
{
    CommandLineOptions()
        : presentationPath(u"templates/presentation.pptx")
        , outVideoPath(u"./video.mp4")
        , fps(30)
    {}

    System::String presentationPath;
    System::String outVideoPath;
    int32_t fps;
};

#endif /* COMMAND_LINE_OPTIONS_H */
