FROM centos:8.1.1911

RUN yum install -y \
    unzip \
    cmake \
    make \
    clang \
    fontconfig \
    mesa-libGL \
    libGLU

VOLUME /slides-cpp
WORKDIR /slides-cpp/sample/

CMD ./build_sample.sh
