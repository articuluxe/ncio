#include <iostream>
#include <ncio/ncio.hpp>
#include <ncio/nc_engine.hpp>

class example_app : public ncio::engine<example_app>
{
 public:
   /* bool init(ncio::config& cfg); */
   void prerun();
   bool loop(ncio::input_event event);

   /* void preframe(); */
   /* void frame(); */
   //  void postrun();

 private:
   ncio::window_ptr win_;
   ncio::input::string str_;
};

/* bool example_app::init(ncio::config& cfg) */
/* {return ncio::engine<example_app>::init(cfg);} */

void example_app::prerun()
{
   win_ = std::make_shared<ncio::window>(
      ncio::bounds(25, 25), ncio::coord(1, 1));
      /* ncio::make_std_win(); */
   get_ctx().get_display().add_win(win_);
   win_->make_box(0, 0);
}

bool example_app::loop(ncio::input_event event)
{
   bool keep_running = true;
   ncio::output::string log(win_);
   log() << ncio::coord(1, 18) << "Entered " << str_.str();
   if (event.ch == 'q')
      keep_running = false;
   return keep_running;
}

/* void example_app::preframe() */
/* {get_ctx().get_input().read_raw();} */

/* void example_app::frame() */
/* { */
/* } */

/* void example_app::postrun() */
/* {} */

int main(int /* argc */, char* /* argv */[])
{
   example_app app;
   ncio::config cfg;
   /* cfg.show_cursor = true; */
   if (false == app.init(cfg))
      return 1;

   app.run();

   /* refresh(); */
   /* window->refresh(); */


   /* window->refresh(); */


   return 0;
}
