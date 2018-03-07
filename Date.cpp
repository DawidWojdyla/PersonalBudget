#include "Date.h"
#include "windows.h"
#define FIRST 1

Date::Date()
{
    setTodaysDateComponents();
    setTodaysIntDate();
    setTodaysStringDate();
    setPreviousMonthDateComponents();
}

const int Date::daysInEachMonth [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::setTodaysDateComponents()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    thisDay = st.wDay;
    thisMonth = st.wMonth;
    thisYear = st.wYear;
}
void Date::setPreviousMonthDateComponents()
{
    if(thisMonth > 1)
    {
        previousMonth = thisMonth - 1;
        yearOfPreviousMonth = thisYear;
    }
    else
    {
        previousMonth = 12;
        yearOfPreviousMonth = thisYear - 1;
    }
    daysOfPreviousMonth = getDaysInTheMonth(previousMonth, yearOfPreviousMonth);
}
void Date::setTodaysStringDate()
{
    todaysStringDate = returnStringDate(thisDay, thisMonth, thisYear);
}
void Date::setTodaysIntDate()
{
    todaysIntDate = returnIntDate(thisDay, thisMonth, thisYear);
}
int Date::returnIntDate(int day, int month, int year)
{
    return year * 10000 + month * 100 + day;
}
string Date::returnStringDate(int day, int month, int year)
{
    string stringDate = "";
    stringDate += typeConversion.intToString(thisYear) + "-";
    if(month < 10)
        stringDate += "0";
    stringDate += typeConversion.intToString(thisMonth) + "-";
    if(day < 10)
        stringDate += "0";
    stringDate += typeConversion.intToString(thisDay);

    return stringDate;
}
string Date::returnStringDate(int date)
{
    string stringDate = typeConversion.intToString(date);
    stringDate.insert(4,"-");
    stringDate.insert(7,"-");

    return stringDate;
}
string Date::getTodaysStringDate()
{
    return todaysStringDate;
}
int Date::getTodaysIntDate()
{
    return todaysIntDate;
}
int Date::getThisDay()
{
    return thisDay;
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
    if(dayToCheck < 1 || dayToCheck > getDaysInTheMonth(monthToCheck, yearToCheck))
        return false;

    return true;
}
int Date::getDaysInTheMonth(int month, int year)
{
    if(isLeapYear(year) && month == 2)
        return 29;
    return daysInEachMonth[month-1];
}
bool Date::isLeapYear(int year)
{
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return true;
    return false;
}
int Date::returnIntDateOfFirstDayOfPreviousMonth()
{
    return returnIntDate(FIRST , previousMonth, yearOfPreviousMonth);
}
int Date::returnIntDateOfTheLastDayOfPreviousMonth()
{
    return returnIntDate(daysOfPreviousMonth, previousMonth, yearOfPreviousMonth);
}
