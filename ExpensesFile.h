#ifndef ExpensesFile_h
#define ExpensesFile_h
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Expense.h"
#include "TypeConversion.h"

using namespace std;

class ExpensesFile
{
    friend class Expenses;
    string expensesFileName;
    vector <Expense> expensesVector;
    CMarkup expensesXML;
    TypeConversion typeConversion;

public:
    ExpensesFile();
    void addExpense(Expense &expense);
    void loadExpensesToVector();
};

#endif
