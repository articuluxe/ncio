// -*- Mode: c++ -*-
// nc_output.hpp --- ncio output helpers
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-15 17:51:35 dharms>
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

#ifndef __NCIO_NC_OUTPUT_HPP__
#define __NCIO_NC_OUTPUT_HPP__

#include "nc_config.hpp"
#include "nc_window.hpp"

#include <iostream>
#include <sstream>

namespace ncio {

//----------------------------------------------------------------------------
//---- buf -------------------------------------------------------------------
//----------------------------------------------------------------------------
class buf : public std::stringbuf
{
 public:
   buf(window_ptr win) : win_(win)
   {}
   buf(buf&& rhs)
      : std::stringbuf(std::move(rhs))
      , win_(rhs.win_)
   {}
   ~buf() { sync(); }

   int sync() override;

   window_ptr get_win() { return win_; }

 private:
   window_ptr win_ = nullptr;
};

struct buf_wrapper
{
   buf b;
   buf_wrapper(window_ptr w) : b(w) {}
   buf_wrapper(buf_wrapper&& rhs)
      : b(std::move(rhs.b))
   {}
};

//----------------------------------------------------------------------------
//---- stream ----------------------------------------------------------------
//----------------------------------------------------------------------------
/* class stream : private buf_wrapper */
/*              , public std::ostream */
class stream : public std::ostream
{
 public:
   stream(window_ptr win)
      : std::ostream(&buf_)
      , buf_(win)
      /* : buf_wrapper(win) */
      /* , std::ostream(&b) */
   {
      iword(index()) = 1;
   }
   stream(stream&& rhs)
      /* : buf_wrapper(std::move(rhs)) */
      /* , std::ostream(std::move(rhs)) */
      : buf_(std::move(rhs.buf_))
   {}

   window_ptr get_win() { return buf_.get_win(); }

   static int index()
   {
      static const int index = std::ios_base::xalloc();
      return index;
   }

 private:
   buf buf_;
};

//----------------------------------------------------------------------------
//---- str -------------------------------------------------------------------
//----------------------------------------------------------------------------
class str
{
 public:
   str(window_ptr win)
      : win_(win)
   {}

   stream operator()() const { return stream(win_); }

 private:
   window_ptr win_;
};

inline std::ostream& operator<<(std::ostream& out, coord where)
{
   if (out.iword(stream::index()))
   {
      wmove(*static_cast<stream&>(out).get_win()
         , std::get<1>(where), std::get<0>(where));
   }
   return out;
}

inline std::ostream& bold(std::ostream& out)
{attron(A_BOLD); return out;}

//----------------------------------------------------------------------------
//---- output ----------------------------------------------------------------
//----------------------------------------------------------------------------
class output
{
 public:
   bool init(config& cfg);
};

inline bool output::init(config& cfg)
{
   curs_set(cfg.show_cursor ? TRUE : FALSE);
   return true;
}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_OUTPUT_HPP__ */

// code ends here
