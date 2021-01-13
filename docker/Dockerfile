# multiarch dev environment for arm64 (r-pi 3b+)
# by hos-b

# base image
FROM ubuntu:20.04

# create user
RUN useradd -rm -d /home/embed -s /bin/bash -g root -G sudo -u 1001 embed
RUN mkdir -p /home/embed/software
RUN mkdir -p /home/embed/data

# symlink python3 to python
RUN ln -s /usr/bin/python3 /usr/bin/python

# non-interactive
ENV DEBIAN_FRONTEND noninteractive
RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# add arm64 architecture
RUN apt-get update
RUN apt-get install -y --no-install-recommends apt-utils
RUN dpkg --add-architecture arm64

## arch-qualify the current repositories
RUN sed -i "s/deb h/deb [arch=amd64] h/g" /etc/apt/sources.list

## add arm64's repos
RUN echo "############################################################################" >> /etc/apt/sources.list
RUN echo "# arm64 repositories" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal main restricted" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-updates main restricted" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal universe" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-updates universe" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal multiverse" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-updates multiverse" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-backports main restricted universe multiverse" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-security main restricted" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-security universe" >> /etc/apt/sources.list
RUN echo "deb [arch=arm64] http://ports.ubuntu.com/ubuntu-ports focal-security multiverse" >> /etc/apt/sources.list

# install arm64 cross-compilation toolchain
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y --no-install-recommends libavcodec-dev:arm64 libavformat-dev:arm64
RUN apt-get install -y --no-install-recommends python3-dev
RUN apt-get install -y --no-install-recommends python3-numpy
RUN apt-get install -y --no-install-recommends libpython3-dev:arm64
RUN apt-get install -y --no-install-recommends libgtk-3-dev:arm64 libcanberra-gtk3-dev:arm64
RUN apt-get install -y --no-install-recommends libtiff-dev:arm64 zlib1g-dev:arm64
RUN apt-get install -y --no-install-recommends libjpeg-dev:arm64 libpng-dev:arm64
RUN apt-get install -y --no-install-recommends crossbuild-essential-arm64
RUN apt-get install -y --no-install-recommends libswscale-dev:arm64 libv4l-dev:arm64
RUN apt-get update

# typical software
RUN apt-get install -y --no-install-recommends cmake git pkg-config wget

# change to user
USER embed
WORKDIR /home/embed