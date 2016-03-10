// -*- Mode: c++ -*-
// nc_input.hpp --- ncio input helpers
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-11 07:20:49 dharms>
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

#ifndef __NCIO_NC_INPUT_HPP__
#define __NCIO_NC_INPUT_HPP__

#include "nc_config.hpp"

#include <ncurses.h>

namespace ncio {

//----------------------------------------------------------------------------
//---- input -----------------------------------------------------------------
//----------------------------------------------------------------------------
class input
{
 public:
   bool init(config& cfg);
   void cleanup()
   {}

};

inline bool input::init(config& /* cfg */)
{
   noecho();                    /*don't echo keys*/
   raw();                       /*disable line buffering*/
   ESCDELAY = 0;                /*don't pause on ESC*/
   nonl();                      /*turn off newline conversions*/
   return true;
}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_INPUT_HPP__ */

// code ends here
