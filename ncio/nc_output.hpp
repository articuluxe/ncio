// -*- Mode: c++ -*-
// nc_output.hpp --- ncio output helpers
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

   int sync() override;
};

//----------------------------------------------------------------------------
//---- stream ----------------------------------------------------------------
//----------------------------------------------------------------------------
class stream : public std::ostream
{
 public:
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
   str(window win)
      : win_(win)
   {}

   stream operator()();

 private:
   window win_;
};

//----------------------------------------------------------------------------
//---- output ----------------------------------------------------------------
//----------------------------------------------------------------------------
class output
{
 public:
   bool init(config& cfg);
};

inline bool output::init(config& /* cfg */)
{return true;}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_OUTPUT_HPP__ */

// code ends here
