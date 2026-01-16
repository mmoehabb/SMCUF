#!/bin/bash

commands=(build flash)

invalidUsage () {
    echo "Valid Usage: ./goweb <command>"
    echo "commands:"
    for command in ${commands[@]}; do
      printf "\t$command\n"
    done
    exit 1
}

if [ -z $1 ]; then
  invalidUsage
fi

if [ $1 == build ]; then
  set -xe
  rm -rf build
  mkdir build
  cd build
  cmake ..
elif [ $1 == flash ]; then
  set -xe
  cd build
  sudo make upload
else
  invalidUsage
fi
