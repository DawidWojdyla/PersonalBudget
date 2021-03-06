#ifndef HomeBudget_h
#define HomeBudget_h
#include <iostream>
#include "Incomes.h"
#include "Expenses.h"


using namespace std;

class HomeBudget
{
    Incomes incomes;
    Expenses expenses;

public:
    HomeBudget();
    void setUserID(int userID);
    void logOff();
    void addNewIncome();
    void addNewExpense();
    void showBalanceOfCurrentMonth();
    void showBalanceOfPreviousMonth();
    void showBalanceOfSelectedPeriod();
};

#endif
