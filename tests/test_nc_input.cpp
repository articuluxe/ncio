#include <gtest/gtest.h>
#include <ncio/nc_input.hpp>

TEST(nc_input, null_creation)
{
   ncio::input_event null;
   EXPECT_FALSE(null);
   EXPECT_TRUE(!null);
}

TEST(nc_input, creation)
{
   ncio::input_event inp('s');
   EXPECT_TRUE(inp);
   EXPECT_FALSE(!inp);
   inp.clear();
   EXPECT_FALSE(inp);
   EXPECT_TRUE(!inp);
}
