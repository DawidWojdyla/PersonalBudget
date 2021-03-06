#ifndef IncomesFile_h
#define IncomesFile_h
#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "Markup.h"
#include "TypeConversion.h"

using namespace std;

class IncomesFile
{
    friend class Incomes;
    vector <Income> incomesVector;
    CMarkup incomesXML;
    string incomesFileName;
    TypeConversion typeConversion;
    bool isIncomesVectorSortedByDate;
    void sortIncomesByDate();

public:
    IncomesFile();
    void addIncome(Income &income);
    void loadIncomesToVector();

};

#endif
