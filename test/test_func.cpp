#include <gtest/gtest.h>
#include "func.h"

TEST(test_A_class, add)
{
    A a(1,3);
    ASSERT_TRUE(a.add() == 4) << "add() is not 4";
}
