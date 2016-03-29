// -*- Mode: c++ -*-
// nc_context.cpp --- ncio context
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March 16, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-16 12:38:48 dharms>
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

#include "nc_context.hpp"
#include "nc_signal.hpp"

#include <csignal>

namespace ncio {

//----------------------------------------------------------------------------
//---- context ---------------------------------------------------------------
//----------------------------------------------------------------------------
context::context()
{
   initscr();
   signal_handler::inst().register_cb(SIGWINCH,
      std::bind(&context::on_bounds_changed, this, std::placeholders::_1));
}

context::~context()
{
   endwin();
}

void context::on_bounds_changed(int /* sig */)
{}

}   // end namespace ncio

// code ends here
