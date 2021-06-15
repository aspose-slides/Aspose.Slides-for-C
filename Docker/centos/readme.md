### For using the Aspose.Slides for C++ in a docker container need to complete several steps:

1. Install Docker on a host system;
2. Build an image. A terminal working directory should contain a file **Dockerfile**:

```docker build -t aspose-slides-centos8.1 .```

3. Download and unzip Aspose.Slides for C++;
4. Share the folder with Aspose.Slides for C++ to allow Docker use it(For Windows: Settings -> Resources -> File Sharing)
5. Run the image as a container via following command:

```docker run --name slides-cpp-centos8 -v d:\aspose-slides-cpp-linux-21.6:/slides-cpp aspose-slides-centos8.1```

You should see building and executing samples.

For second and subsequent launches need to use:

```docker start slides-cpp-centos8 -i```

