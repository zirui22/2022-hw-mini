#!/usr/bin/env bash

# Installs CMake: Intel x86_64 Linux only

set -e

cd $HOME

version=3.24.2
name=cmake-$version-linux-x86_64
archive=$name.tar.gz

if [[ $(uname -m) != "x86_64" ]] || [[ "$OSTYPE" != "linux-gnu" ]]
then
  echo "ERROR: this script is for Intel x86_64 Linux only"
  exit 1
fi

# downloads binary archive if necessary
[[ -f $archive ]] || curl -L -O https://github.com/Kitware/CMake/releases/download/v$version/$archive

tar -x -f $archive

export PATH=$HOME/$name/bin:$PATH

echo "please add the following line to your $HOME/.bashrc file"
echo "export PATH=$HOME/$name/bin:\$PATH"
