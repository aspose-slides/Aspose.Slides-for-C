### For using the Aspose.Slides for C++ in a docker container need to complete several steps:

1. Install Docker on a host system;
2. Build an image. A terminal working directory should contain a file **Dockerfile**:

```docker build -t aspose-slides-ubuntu-16.04 --build-arg accept_msttcorefonts_eula=true .```

3. Download and unzip Aspose.Slides for C++;
4. Share the folder with Aspose.Slides for C++ to allow Docker use it(For Windows: Settings -> Resources -> File Sharing)
5. Run the image as a container via following command:

```docker run --name slides-cpp-ubuntu -v d:\aspose-slides-cpp-linux-21.6:/slides-cpp aspose-slides-ubuntu-16.04```

You should see building and executing samples.

For second and subsequent launches need to use:

```docker start slides-cpp-ubuntu -i```

For more details see this [article](https://docs.aspose.com/slides/cpp/how-to-run-aspose-slides-cpp-in-docker/).