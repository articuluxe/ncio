// -*- Mode: c++ -*-
// nc_engine.hpp --- ncio engine
// Copyright (C) 2016-2017  Dan Harms (dharms)
// Author: Dan Harms <danielrharms@gmail.com>
// Created: Thursday, March 10, 2016
// Version: 1.0
// Modified Time-stamp: <2017-10-02 08:51:16 dharms>
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

#ifndef __NCIO_NC_ENGINE_HPP__
#define __NCIO_NC_ENGINE_HPP__

#include "nc_context.hpp"
#include <atomic>
#include <chrono>
#include <thread>

namespace ncio {

//----------------------------------------------------------------------------
//---- engine ----------------------------------------------------------------
//----------------------------------------------------------------------------
template <typename T>
class engine
{
 public:
   engine();
   ~engine();
   context& get_ctx() { return ctx_; }

   bool init(config& cfg);
   void run();
   void halt() { run_ = false; }

 protected:
   context ctx_;

 private:
   std::atomic<bool> run_;

   void prerun() {}
   void postrun() {}

   bool loop(input_event event);

};

template <typename T>
engine<T>::engine()
   : run_(false)
{}

template <typename T>
engine<T>::~engine()
{}

template <typename T>
inline bool engine<T>::init(config& cfg)
{return ctx_.init(cfg);}

template <typename T>
inline void engine<T>::run()
{
   T* app = static_cast<T*>(this);
   refresh();
   run_ = true;
   app->prerun();
   ctx_.prerun();
   input_event event = ctx_.get_display().read_event();
   while (run_)
   {
      ctx_.preloop();
      run_ = app->loop(event);
      ctx_.postloop();
      event.clear();
      while (run_ && !event)
      {
         std::this_thread::sleep_for(std::chrono::milliseconds(50));
         event = ctx_.get_display().read_event();
      }
      /* app->preframe(); */
      /* app->frame(); */
      /* app->postframe(); */
   }
   app->postrun();
}

}   // end namespace ncio

#endif   /* #ifndef __NCIO_NC_ENGINE_HPP__ */

// code ends here
