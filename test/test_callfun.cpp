#include <gtest/gtest.h>
#include "callfun.h"

TEST(test_call_fun, getNumber)
{
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(1);
    ASSERT_TRUE(getNumber(numbers) == 2) << " getNumber() is not 2";
}