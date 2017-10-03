// -*- Mode: c++ -*-
// nc_window.hpp --- ncio window
// Copyright (C) 2016-2017  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2017-10-03 08:34:00 dharms>
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
   coord(int x, int y) : std::tuple<int, int>(x, y) {}
};

//----------------------------------------------------------------------------
//---- bounds ----------------------------------------------------------------
//----------------------------------------------------------------------------
struct bounds : std::tuple<int, int>
{
   bounds(int x, int y) : std::tuple<int, int>(x, y) {}
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
   {
   }
   window(WINDOW* win)
      : win_(win)
   {
   }

   ~window()
   {
      if (win_ != stdscr)
         delwin(win_);
   }

   operator WINDOW*() const { return win_; }

   void refresh() { wrefresh(win_); }
   void clear() { wclear(win_); }
   void draw();

   bounds get_bounds() const;
   /* input::string read_string(); */

   bool getBorder() const { return border_; }
   void setBorder(bool val) { border_ = val; }

 private:
   WINDOW* win_;
   bool border_ = true;
};

inline bounds window::get_bounds() const
{
   int x, y;
   getmaxyx(win_, y, x);
   bounds ret(x, y);
   return ret;
}

inline void window::draw()
{
   if (border_)
   {
      box(win_, '|', '-');
   }
}

/* inline input::string read_string() */
/* {return input::string{}.read(*this);} */

/* inline void del_win(WINDOW* /\* win *\/) */
/* {} */

using window_ptr = std::shared_ptr<window>;

inline window_ptr make_std_win()
{return std::shared_ptr<window>(new ncio::window(stdscr));}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_WINDOW_HPP__ */

// code ends here
