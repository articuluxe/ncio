// -*- Mode: c++ -*-
// nc_display.hpp --- ncio display
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Thursday, March 10, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-17 17:53:40 dharms>
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
#include "nc_input.hpp"
#include "nc_config.hpp"
#include <algorithm>
#include <vector>
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
   input& get_input() { return inp_; }
   input_event read_event();

   void prerun();
   void postloop();

   void on_bounds_updated();
   struct screen
   {
      coord get_bounds();
   };

   void add_win(window_ptr win);

   template <typename Fun>
   void apply_win(Fun fun)
   {
      std::for_each(wins_.begin(), wins_.end(), fun);
   }

 private:
   input inp_;
   std::vector<window_ptr> wins_;
   window_ptr curr_;
};

inline bool display::init(config& cfg)
{
   if (!inp_.init(cfg_))
      return false;
   if (!cfg.show_cursor)
      curs_set(FALSE);
   return true;
}

inline input_event display::read_event()
{
   if (curr_)
   {
      input_event event = input::read_event(*curr_);
//      input::string str = input::read_string(*curr_);
   }
}

inline void display::add_win(window_ptr win)
{
   nodelay(*win, TRUE);
   wins_.push_back(win);
}

inline void display::prerun()
{apply_win(std::bind(&window::refresh, std::placeholders::_1));}

inline void display::postloop()
{apply_win(std::bind(&window::refresh, std::placeholders::_1));}

inline void display::on_bounds_updated()
{}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_DISPLAY_HPP__ */

// code ends here
