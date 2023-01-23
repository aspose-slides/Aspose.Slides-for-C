#include <string>
#include <vector>
#include <iostream>

#include <system/string.h>
#include <system/io/path.h>

#include "pptx2video_converter.h"
#include "command_line_options.h"
#include "ffmpeg_failed_exception.h"

using namespace System::IO;

int main(int argc, char* argv[])
{
    if (argc > 7)
    {
        std::cerr << "Too much arguments!" << std::endl;
        return 1;
    }

    const std::vector<std::string> args(argv + 1, argv + argc);
    CommandLineOptions options;

    for (std::size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == "-i" || args[i] == "--input")
        {
            options.presentationPath = args[++i];
        }
        else if (args[i] == "-o" || args[i] == "--output")
        {
            options.outVideoPath = args[++i];
        }
        else if (args[i] == "-f" || args[i] == "--fps")
        {
            options.fps = stoi(args[++i]);
        }
        else
        {
            std::cerr << "Unknown option " << args[i] << std::endl;
            return 1;
        }
    }

    try
    {
        const System::String outVideoPath(options.outVideoPath);
        const System::String tempFolderPath = Path::Combine(Path::GetDirectoryName(outVideoPath), u"images");

        auto presentation = System::MakeObject<Presentation>(System::String(options.presentationPath));
        auto converter = System::MakeObject<Pptx2VideoConverter>(
            presentation, outVideoPath, tempFolderPath, options.fps);

        std::cout << "Generating frames..." << std::endl;
        converter->GenerateFrames();
        std::cout << "Launching FFmpeg to join frames into video..." << std::endl;
        converter->RunFFmpeg();
        return 0;
    }
    catch (const System::Exception& ex)
    {
        std::cerr << "Exception occurred: " << std::endl << ex.ToString() << std::endl;
        return 1;
    }
}
