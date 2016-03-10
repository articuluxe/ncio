// -*- Mode: c++ -*-
// nc_window.hpp --- ncio window
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-11 07:35:44 dharms>
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

#ifndef __NCIO_NC_WINDOW_HPP__
#define __NCIO_NC_WINDOW_HPP__

#include <memory>
#include <tuple>
#include <ncurses.h>

namespace ncio {

using coord = std::tuple<int, int>;
using bounds = std::tuple<int, int>;

void del_win(WINDOW* win);
using window = std::shared_ptr<WINDOW>;
inline window make_window(coord origin, bounds extent)
{
   return window(newwin(
         std::get<0>(origin), std::get<1>(origin),
         std::get<0>(extent), std::get<1>(extent))
      , del_win);
}

inline void del_win(WINDOW* win) {delwin(win);}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_WINDOW_HPP__ */

// code ends here
