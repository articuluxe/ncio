#!/bin/sh
# -*- Mode: sh -*-
# genbuild.sh --- set up build environment
# Copyright (C) 2016-2017  Dan Harms (dharms)
# Author: Dan Harms <danielrharms@gmail.com>
# Created: Wednesday, January 27, 2016
# Version: 1.0
# Modified Time-stamp: <2017-08-22 17:33:15 dharms>
# Modified by: Dan Harms
# Keywords:

mkdir -p debug
cd debug
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER="${CC}" -DCMAKE_CXX_COMPILER="${CXX}"
cd ..

mkdir -p release
cd release
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER="${CC}" -DCMAKE_CXX_COMPILER="${CXX}"
cd ..

# code ends here
