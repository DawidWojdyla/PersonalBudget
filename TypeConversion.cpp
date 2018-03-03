#include "TypeConversion.h"

string TypeConversion::intToString(int intVariable)
{
    ostringstream buffer;
    buffer << intVariable;
    string stringVariable = buffer.str();
    return stringVariable;
}

 string TypeConversion::doubleToString(double doubleVariable)
 {
    ostringstream buffer;
    buffer << fixed <<setprecision(2) << doubleVariable;
    string stringVariable = buffer.str();
    return stringVariable;
 }

int TypeConversion::stringDateToInt(string originalDate)
{
    string preparedForConversionDate = "";
    preparedForConversionDate = originalDate.substr(0,4) + originalDate.substr(5,2) + originalDate.substr(8,2);
    return atoi(preparedForConversionDate.c_str());
}
