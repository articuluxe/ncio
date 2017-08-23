// -*- Mode: c++ -*-
// nc_input.hpp --- ncio input helpers
// Copyright (C) 2016-2017  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2017-07-07 08:27:31 dharms>
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
#include "nc_window.hpp"

#include <string>
#include <vector>
#include <ncurses.h>

namespace ncio {

namespace input_mode {

//----------------------------------------------------------------------------
//---- mode ------------------------------------------------------------------
//----------------------------------------------------------------------------
struct mode
{
   bool cooked = false;
   mode() = default;
   constexpr mode(bool val = false) : cooked(val) {}
};

constexpr mode raw{false};
constexpr mode cooked{true};

}   // end namespace input_mode

//----------------------------------------------------------------------------
//---- input_event -----------------------------------------------------------
//----------------------------------------------------------------------------
struct input_event
{
   input_event() = default;
   input_event(char c) : ch(c)
   {}

   int ch;
};

//----------------------------------------------------------------------------
//---- input -----------------------------------------------------------------
//----------------------------------------------------------------------------
class input
{
 public:

   /* struct mode */
   /* { */
   /*    bool buffered; */
   /*    mode() = default; */
   /*    constexpr mode(bool b) : buffered(b) {} */
   /* }; */

   /* static constexpr input::mode buffered{true}; */
   /* static constexpr input::mode unbuffered{false}; */

   bool init(config& cfg);
   void cleanup()
   {}

   static int read_buffered(const window& win);
   static int read_raw(const window& win);

   using input_events = std::vector<input_event>;
   input_event read_event(const window& win)
   {
      int ch = wgetch(win);
      return ch;
   }

   class string
   {
    public:
      string() = default;
      string(std::string str) : str_(std::move(str)) {}
      operator std::string() const { return str_; }
      std::string str() const { return str_; }
      void reset() { str_.clear(); }

//      std::string read(mode md = buffered)
      std::string read(const window& win
         , input_mode::mode mode = input_mode::raw)
      {
         str_.push_back(mode.cooked ? read_buffered(win) : read_raw(win));
         return str_;
      }

    private:
      std::string str_;
      window_ptr win_;
   };

   string read_string(const window& win) const
   { return string().read(win, input_mode::mode(cooked_)); }


 private:
   bool cooked_ = false;
};

inline bool input::init(config& /* cfg */)
{
   noecho();                    /*don't echo keys*/
   raw();                       /*disable line buffering*/
//   halfdelay(1);
   ESCDELAY = 0;                /*don't pause on ESC*/
   nonl();                      /*turn off newline conversions*/
   keypad(stdscr, TRUE);        /*TODO: move to window?*/
   return true;
}

/* static */ inline int input::read_buffered(const window& win)
{
   return wgetch(win);
}

/* static */ inline int input::read_raw(const window& win)
{
   return wgetch(win);
}

/* /\* static *\/ inline input_event input::read_event() */
/* { */
/*    return input_event{}; */
/* } */

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_INPUT_HPP__ */

// code ends here
