// -*- Mode: c++ -*-
// nc_display.hpp --- ncio display
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Thursday, March 10, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-11 07:18:00 dharms>
// Modified by: Dan Harms
// Keywords: ncurss c++

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

#ifndef __NCIO_NC_DISPLAY_HPP__
#define __NCIO_NC_DISPLAY_HPP__

#include "nc_window.hpp"
#include "nc_config.hpp"

#include <ncurses.h>

namespace ncio {

//----------------------------------------------------------------------------
//---- display ---------------------------------------------------------------
//----------------------------------------------------------------------------
class display
{
 public:
   bool init(config& cfg);
   void cleanup()
   {}

   void on_bounds_updated();
   struct screen
   {
      coord get_bounds();
   };

};

inline bool display::init(config& cfg)
{
   if (!cfg.show_cursor)
      curs_set(FALSE);
   return true;
}

inline void display::on_bounds_updated()
{}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_DISPLAY_HPP__ */

// code ends here
