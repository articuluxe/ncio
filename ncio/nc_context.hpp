// -*- Mode: c++ -*-
// nc_context.hpp --- ncio context
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Friday, March 11, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-11 07:16:06 dharms>
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

#ifndef __NCIO_NC_CONTEXT_HPP__
#define __NCIO_NC_CONTEXT_HPP__

#include "nc_config.hpp"
#include "nc_display.hpp"
#include "nc_input.hpp"

#include <ncurses.h>

//----------------------------------------------------------------------------
//---- context ---------------------------------------------------------------
//----------------------------------------------------------------------------
class context
{
 public:
   bool init(config& cfg);
   void cleanup();

 private:
   config cfg_;
   display disp_;
};

inline bool context::init(config& cfg)
{
   initscr();

   disp_.init(cfg);
   return true;
}

inline context::~context()
{endwin();}


#endif   /* #ifndef __NCIO_NC_CONTEXT_HPP__ */

// code ends here
