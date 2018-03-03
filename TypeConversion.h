#ifndef TypeConversion_h
#define TypeConversion_h
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class TypeConversion
{
public:
    string intToString(int number);
    string doubleToString (double);
    int stringDateToInt(string date);
};

#endif
