# /bin/bash

set -xe

rm -rf build
mkdir build
cd build

cmake ..
make upload
