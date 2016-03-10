#!/bin/sh
# -*- Mode: sh -*-
# setup.sh --- set up build environment
# Copyright (C) 2016  Dan Harms (dharms)
# Author: Dan Harms <danielrharms@gmail.com>
# Created: Wednesday, January 27, 2016
# Version: 1.0
# Modified Time-stamp: <2016-02-08 07:50:57 dharms>
# Modified by: Dan Harms
# Keywords:

mkdir -p debug
cd debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
cd ..

mkdir -p release
cd release
cmake .. -DCMAKE_BUILD_TYPE=Release
cd ..

# code ends here
