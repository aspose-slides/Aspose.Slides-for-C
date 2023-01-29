#include <string>
#include <vector>
#include <iostream>

#include <system/string.h>
#include <system/io/path.h>

#include "pptx2video_converter.h"
#include "command_line_options.h"

using namespace System::IO;

int main(int argc, char* argv[])
{
    const std::vector<std::string> args(argv + 1, argv + argc);
    CommandLineOptions options;

    for (std::size_t i = 0; i < args.size(); i++)
    {
        if (args[i] == "-i" || args[i] == "--input")
        {
            options.presentationPath = System::String(args[++i]);
        }
        else if (args[i] == "-o" || args[i] == "--output")
        {
            options.outVideoPath = System::String(args[++i]);
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
        const System::String tempFolderPath = Path::Combine(Path::GetDirectoryName(options.outVideoPath), u"generated_frames");

        auto presentation = System::MakeObject<Presentation>(options.presentationPath);
        auto converter = System::MakeObject<Pptx2VideoConverter>(presentation, options.outVideoPath, tempFolderPath, options.fps);

        std::cout << "Generating frames..." << std::endl;
        converter->GenerateFrames();
        std::cout << "Launching FFmpeg to join frames into video..." << std::endl;
        converter->RunFFmpeg();
        std::cout << "Done." << std::endl;
        return 0;
    }
    catch (const System::Exception& ex)
    {
        std::cerr << "Exception occurred:" << std::endl << ex.ToString() << std::endl;
        return 1;
    }
}
