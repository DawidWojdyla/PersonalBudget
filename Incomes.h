#ifndef Incomes_h
#define Incomes_h
#include <iostream>
#include <windows.h>
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
    double totalIncome;
    void addNewIncome(string corectDate);
    vector <Income> returnSelectedIncomes(int dateFrom);
    vector <Income> returnSelectedIncomes(int dateFrom, int dateTo);
    void showIncomes(vector <Income> &incomes);

public:
    Incomes();
    void addNewIncome();
    void setUserID(int userID);
    void showIncomesOfCurrentMonth();
    void showIncomesOfPreviousMonth();
    void showIncomesOfSelectedPeriod(string stringDateFrom, string stringDateTo);
    double getTotalIncome();
};

#endif
