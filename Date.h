#ifndef Date_h
#define Date_h
#include <iostream>
#include "ExpensesFile.h"

using namespace std;

class Date
{
    friend class Incomes;
    friend class Expenses;
    string todaysDate;
    int todaysDateInt;
    int thisDay, thisMonth, thisYear;
    static const int daysInEachMonth [];
    TypeConversion typeConversion;
    void setTodaysDate();
    bool leapYear(int year);
    int daysInTheMonth(int month, int year);
public:
    Date();
    string getTodaysDate();
    bool validateDate(string dateToCheck);

};

#endif
