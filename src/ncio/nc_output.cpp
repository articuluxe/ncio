// -*- Mode: c++ -*-
// nc_output.cpp --- ncio output
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Thursday, March 10, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-16 06:15:20 dharms>
// Modified by: Dan Harms
// Keywords: ncurses c++

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// Commentary:

// Code:

#include "nc_output.hpp"

namespace ncio {

int buf::sync()
{
   wprintw(*win_, str().c_str());
   str("");
   return 0;
}

}   // end namespace ncio

// code ends here
