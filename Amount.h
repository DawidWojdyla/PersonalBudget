#ifndef Amount_h
#define Amount_h
#include <iostream>
#include "TypeConversion.h"

using namespace std;

class Amount
{
    friend class Incomes;
    TypeConversion typeConversion;
    int amountLength;
    int numberOfDots;
    string commasToDots(string amount);
public:
    Amount();
    bool checkAmount(string &amount);
};


#endif
