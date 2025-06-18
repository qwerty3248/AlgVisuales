#!/bin/bash
sudo apt update
sudo apt install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools cmake build-essential
mkdir -p build
cd build
cmake ..
make