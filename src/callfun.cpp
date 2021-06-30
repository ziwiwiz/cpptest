#include "callfun.h"

int getNumber(const std::vector<int>& numbers)
{
    int  res = 0;
    for (auto i:numbers)
    {
        res ^= i;
    }
    return res;
}