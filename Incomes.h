#ifndef Incomes_h
#define Incomes_h
#include <iostream>
#include <windows.h>
#include <algorithm>
#include "IncomesFile.h"
#include "Date.h"
#include "Amount.h"

using namespace std;

class Incomes
{
    friend class HomeBudget;
    IncomesFile incomesFile;
    Date dateOperator;
    Amount amountOperator;
    int userID;
    void addNewIncome(string corectDate);
    void sortIncomesByDate();
public:
    Incomes();
    void setUserID(int userID);
    void addNewIncome();
    double showIncomesOfCurrentMonth();
    double showIncomesOfPreviousMonth();
    double showIncomesOfSelectedPeriod(string stringDateFrom, string stringDateTo);
};

#endif
