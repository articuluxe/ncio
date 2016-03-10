// -*- Mode: c++ -*-
// nc_config.hpp --- ncio configuration
// Copyright (C) 2016  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Wednesday, March  9, 2016
// Version: 1.0
// Modified Time-stamp: <2016-03-09 22:44:29 dharms>
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

#ifndef __NCIO_NC_CONFIG_HPP__
#define __NCIO_NC_CONFIG_HPP__

namespace ncio {

//----------------------------------------------------------------------------
//---- config ----------------------------------------------------------------
//----------------------------------------------------------------------------
struct config
{
   bool show_cursor = false;
};

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_CONFIG_HPP__ */

// code ends here
