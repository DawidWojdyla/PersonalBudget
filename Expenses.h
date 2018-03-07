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
    friend class HomeBudget;
    ExpensesFile expensesFile;
    Date dateOperator;
    Amount amountOperator;
    int userID;
    double totalExpenses;
    void addNewExpense(string);
    vector <Expense> returnSelectedExpenses(int dateFrom);
    vector <Expense> returnSelectedExpenses(int dateFrom, int dateTo);
    void showExpenses(vector <Expense> &expenses);

public:
    Expenses();
    void setUserID(int userID);
    void addNewExpense();
    void showExpensesOfCurrentMonth();
    void showExpensesOfPreviousMonth();
    void showExpensesOfSelectedPeriod(string stringDateFrom, string stringDateTo);
    double getTotalExpenses();
};

#endif
