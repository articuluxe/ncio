// -*- Mode: c++ -*-
// nc_signal.cpp --- ncio signal handler
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Thursday, March 10, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-11 07:38:49 dharms>
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

#include "nc_signal.hpp"

#include <csignal>

void onsig(int sig);

namespace ncio {

//----------------------------------------------------------------------------
//---- signal_handler --------------------------------------------------------
//----------------------------------------------------------------------------
signal_handler& signal_handler::inst()
{
   static signal_handler self;
   return self;
}

signal_handler::signal_handler()
{}

void signal_handler::register_cb(int sig
   , callback cb)
{
   signal(sig, onsig);
   cb_.insert(decltype(cb_)::value_type(sig, cb));
}

void signal_handler::on_signal(int sig)
{
   auto rg = cb_.equal_range(sig);
   for (auto it = rg.first; it != rg.second; ++it)
   {
      (it->second)(sig);
   }
}

}   // end namespace ncio

void onsig(int sig)
{ncio::signal_handler::inst().on_signal(sig);}

// code ends here
