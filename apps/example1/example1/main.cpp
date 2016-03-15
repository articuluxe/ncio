#include <iostream>
#include <ncio/ncio.hpp>

int main(int /* argc */, char* /* argv */[])
{

   ncio::engine e;
   if (!e.init())
      return 1;

   return 0;
}
