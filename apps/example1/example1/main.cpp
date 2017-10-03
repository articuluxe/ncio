#include <iostream>
#include <ncio/ncio.hpp>
#include <ncio/nc_engine.hpp>

class example_app : public ncio::engine<example_app>
{
 public:
   /* bool init(ncio::config& cfg); */
   void prerun();
   bool loop(ncio::input_event event);

 private:
   ncio::input::string str_;
};

void example_app::prerun()
{
   ncio::window_ptr win = std::make_shared<ncio::window>(
      ncio::bounds(25, 25), ncio::coord(1, 1));
   get_ctx().get_display().add_win(win);
}

bool example_app::loop(ncio::input_event event)
{
   bool keep_running = true;
   ncio::output::string log = get_ctx().get_display().get_output();
   auto str = log();
   if (event.ch)
   {
      str << "Entered ";
      int val = event.ch;
      char ch = event.ch;
      if (ch)
      {
         str << ch << ncio::bold << " (" << val << ")";
      }

      str << ncio::coord(2, 5) << std::flush;
   }

   if (event.ch == 'q')
      keep_running = false;
   return keep_running;
}

int main(int /* argc */, char* /* argv */[])
{
   example_app app;
   ncio::config cfg;
   /* cfg.show_cursor = true; */
   if (false == app.init(cfg))
      return 1;

   app.run();

   return 0;
}
