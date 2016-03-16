#include <iostream>
#include <ncio/ncio.hpp>

int main(int /* argc */, char* /* argv */[])
{
   ncio::engine e;
   ncio::config cfg;
   /* cfg.show_cursor = true; */
   if (false == e.init(cfg))
      return 1;

   ncio::window_ptr window =
   /*    std::make_shared<ncio::window>( */
   /*       ncio::bounds(25, 25), ncio::coord(1, 1)); */
      ncio::make_std_win();

   window->make_box(0, 0);
   window->refresh();

   ncio::str log(window);

   ncio::input::string str;
   str.read();
   log() << ncio::coord(1, 18) << "Entered " << str.str();

   window->refresh();

//   refresh();
   ncio::input::read_raw();

   return 0;
}
