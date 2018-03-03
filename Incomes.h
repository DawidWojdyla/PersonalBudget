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
    IncomesFile incomesFile;
    Date dateOperator;
    Amount amountOperator;
    int userID;
    void addNewIncome(string corectDate);
public:
    Incomes();
    void setUserID(int userID);
    void addNewIncome();

};

#endif
