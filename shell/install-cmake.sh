#!/bin/bash

# Check if a version argument is provided
CMAKE_VERSION=3.30
BUILD=1
CMAKE_TEMP_DIR=~/cmake-temp-dir
PASSWORD="1"

echo "---------------------------CMAKE INSTALL SCRIPT---------------------------"
if [ -z "$1" ]; then
    echo "No input version provided. $CMAKE_VERSION will be installed."
else
    echo "Installing CMake version : $1"
    CMAKE_VERSION=$1
fi

if [ -z "$2" ]; then
    echo "No input user password. Default password $PASSWORD will be used."
else
    echo "Use password             : $2"
    PASSWORD=$2
fi
echo "---------------------------------------------------------------------------"

function mainTask() {
    mkdir $CMAKE_TEMP_DIR
    cd $CMAKE_TEMP_DIR
    wget https://cmake.org/files/v$CMAKE_VERSION/cmake-$CMAKE_VERSION.$BUILD.tar.gz
    tar -xzvf cmake-$CMAKE_VERSION.$build.tar.gz
    cd cmake-$CMAKE_VERSION.$BUILD/
    ./bootstrap
    make -j$(nproc)
    echo $PASSWORD | sudo -S make install
}

# Install CMake dependencies
echo $PASSWORD | sudo -S apt update
echo $PASSWORD | sudo -S apt install -y build-essential openssl libssl-dev

# Download and install CMake
mainTask

echo "CMake $CMAKE_VERSION installed successfully."

echo $PASSWORD | sudo -S rm -rf $CMAKE_TEMP_DIR

cmake --version