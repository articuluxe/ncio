// -*- Mode: c++ -*-
// nc_signal.hpp --- signal handler
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Thursday, March 10, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-10 18:17:58 dharms>
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

#ifndef __NCIO_NC_SIGNAL_HPP__
#define __NCIO_NC_SIGNAL_HPP__

#include <functional>
#include <map>

namespace ncio {

//----------------------------------------------------------------------------
//---- signal_handler --------------------------------------------------------
//----------------------------------------------------------------------------
class signal_handler
{
 public:
   static signal_handler& inst();

   using callback = std::function<void(int)>;

   void register_cb(int sig, callback cb);
   void on_signal(int sig);

 private:
   signal_handler();

   std::multimap<int, callback> cb_;

};

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_SIGNAL_HPP__ */

// code ends here
