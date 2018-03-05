#ifndef Expenses_h
#define Expenses_h
#include <iostream>
#include <windows.h>
#include <algorithm>
#include "ExpensesFile.h"
#include "Date.h"
#include "Amount.h"

using namespace std;

class Expenses
{
    ExpensesFile expensesFile;
    Date dateOperator;
    Amount amountOperator;
    int userID;
    void addNewExpense(string);
    bool sortExpensesByDate();

public:
    Expenses();
    void setUserID(int userID);
    void addNewExpense();
    double showExpensesOfCurrentMonth();
    double showExpensesOfPreviousMonth();
    double showExpensesOfSelectedPeriod(string stringDateFrom, string stringDateTo);

};

#endif
