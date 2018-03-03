#include "Date.h"
#include "windows.h"

Date::Date()
{
    todaysDate = "";
    setTodaysDate();
    todaysDateInt = typeConversion.stringDateToInt(todaysDate);
}

const int Date::daysInEachMonth [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::setTodaysDate()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    thisDay = st.wDay;
    thisMonth = st.wMonth;
    thisYear = st.wYear;

    todaysDate += typeConversion.intToString(thisYear) + "-";;
    if(thisMonth < 10)
        todaysDate += "0";
    todaysDate += typeConversion.intToString(thisMonth) + "-";
    if(thisDay < 10)
        todaysDate += "0";
    todaysDate += typeConversion.intToString(thisDay);
}
string Date::getTodaysDate()
{
    return todaysDate;
}

bool Date::validateDate(string dateToCheck)
{
    if(dateToCheck.length() != 10)
        return false;

    if(dateToCheck[4] != '-' || dateToCheck[7] != '-')
        return false;

    int yearToCheck, monthToCheck, dayToCheck;

    yearToCheck = atoi(dateToCheck.substr(0,4).c_str());
    if(yearToCheck < 2000 || yearToCheck > thisYear)
       return false;

    monthToCheck = atoi(dateToCheck.substr(5,2).c_str());
    if((monthToCheck <1 || monthToCheck >12) || (yearToCheck == thisYear && monthToCheck > thisMonth))
        return false;

    dayToCheck = atoi(dateToCheck.substr(8,2).c_str());
    if(dayToCheck > daysInTheMonth(monthToCheck, yearToCheck))
        return false;

    return true;
}
int Date::daysInTheMonth(int month, int year)
{
    if(leapYear(year) && month == 2)
        return 29;
    return daysInEachMonth[month-1];
}
bool Date::leapYear(int year)
{
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return true;
    return false;
}
