#ifndef COMMAND_LINE_OPTIONS_H
#define COMMAND_LINE_OPTIONS_H

#include <string>

struct CommandLineOptions
{
    CommandLineOptions()
        : presentationPath("./presentation.pptx")
        , outVideoPath("./video.mp4")
        , fps(30)
    {}

    std::string presentationPath;
    std::string outVideoPath;
    int fps;
};

#endif /* COMMAND_LINE_OPTIONS_H */
