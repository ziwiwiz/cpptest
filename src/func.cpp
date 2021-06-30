#include "func.h"

A::A(int a, int b)
{
    this->a = a;
    this->b = b;
}

A::~A()
{
}

int A::add()
{
    return this->a+this->b;
}
