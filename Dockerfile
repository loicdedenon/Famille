FROM ubuntu:devel
LABEL Description="Build environment"

SHELL ["/bin/bash", "-c"]

ENV HOME /app

# Install tools
RUN apt-get update && apt-get -y --no-install-recommends install \
    ca-certificates \
    build-essential \
    clang \
    cmake \
    gdb \
    git \
    wget \
    && update-ca-certificates

# Install dependencies to build SFML
RUN apt-get update && apt-get -y --no-install-recommends install \
    libflac-dev \
    libgl1-mesa-dev \
    libogg-dev \
    libopenal-dev \
    libopengl-dev \
    libudev-dev \
    libvorbis-dev \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libfreetype6-dev
    
#ENV CPPFLAGS="-I/app/build/_deps/sfml-src/include -I/app/build/_deps/csfml-src/include"
#ENV LDFLAGS="-L/app/build/lib"

#install binaries
RUN apt-get update && apt-get -y --no-install-recommends install \
    libsfml-dev \
    libcsfml-dev

WORKDIR /app

COPY . /app