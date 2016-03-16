// -*- Mode: c++ -*-
// nc_window.hpp --- ncio window
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-16 06:16:09 dharms>
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

//----------------------------------------------------------------------------
//---- coord -----------------------------------------------------------------
//----------------------------------------------------------------------------
struct coord : std::tuple<int, int>
{
   coord(int x, int y) : std::tuple<int, int>(y, x) {}
};

//----------------------------------------------------------------------------
//---- bounds ----------------------------------------------------------------
//----------------------------------------------------------------------------
struct bounds : std::tuple<int, int>
{
   bounds(int x,  int y) : std::tuple<int, int>(y, x) {}
};

//----------------------------------------------------------------------------
//---- window ----------------------------------------------------------------
//----------------------------------------------------------------------------
class window
{
 public:
   window(bounds extent, coord origin)
      : win_(newwin(std::get<1>(extent), std::get<0>(extent),
            std::get<1>(origin), std::get<0>(origin)))
   {}
   window(WINDOW* win)
      : win_(win)
   {}

   ~window()
   {
      if (win_ != stdscr)
         delwin(win_);
   }

   operator WINDOW*() const { return win_; }

   void refresh() { wrefresh(win_); }

   void make_box(int x, int y)
   { box(win_, x, y); }

 private:
   WINDOW* win_;
};


/* inline void del_win(WINDOW* /\* win *\/) */
/* {} */

using window_ptr = std::shared_ptr<window>;

inline window_ptr make_std_win()
{return std::shared_ptr<window>(new ncio::window(stdscr));}

/* inline window_ptr make_window(coord origin, bounds extent) */
/* { */
/*    return window_ptr(window(newwin( */
/*             std::get<0>(origin), std::get<1>(origin), */
/*             std::get<0>(extent), std::get<1>(extent))) */
/*       , del_win); */
/* } */

/* inline void del_win(WINDOW* win) {delwin(win);} */

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_WINDOW_HPP__ */

// code ends here
