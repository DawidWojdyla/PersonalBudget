#include <iostream>
#include <sstream>
#include "TypeConversion.h"

using namespace std;

string TypeConversion::intToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}






