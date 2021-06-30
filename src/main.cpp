#include <iostream>
#include "func.h"
#include "callfun.h"
using namespace std;

int  main()
{
    A a(1,2);
    cout << a.add() << endl;
    vector<int> x;
    x.push_back(1);
    cout << getNumber(x) << endl;
    return 0;
}