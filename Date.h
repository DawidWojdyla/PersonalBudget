#ifndef Date_h
#define Date_h
#include <iostream>
#include "ExpensesFile.h"

using namespace std;

class Date
{
    friend class Incomes;
    friend class Expenses;
    string todaysStringDate;
    int todaysIntDate;
    int thisDay, thisMonth, thisYear;
    int daysOfPreviousMonth, previousMonth, yearOfPreviousMonth;
    static const int daysInEachMonth [];
    TypeConversion typeConversion;
    void setTodaysStringDate();
    void setTodaysIntDate();
    void setTodaysDateComponents();
    void setPreviousMonthDateComponents();
    bool leapYear(int year);
    int daysInTheMonth(int month, int year);
    string returnStringDate(int day, int month, int year);
    int returnIntDate(int day, int month, int year);
public:
    Date();
    string getTodaysStringDate();
    bool validateDate(string dateToCheck);
    int returnIntDateOfFirstDayOfPreviousMonth();
    int returnIntDateOfTheLastDayOfPreviousMonth();


};

#endif
