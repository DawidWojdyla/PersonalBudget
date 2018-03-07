#include "IncomesFile.h"

IncomesFile::IncomesFile()
{
    incomesFileName = "incomes.xml";
    isIncomesVectorSortedByDate = false;
    incomesXML.Load(incomesFileName);
    loadIncomesToVector();
    sortIncomesByDate();
}

void IncomesFile::addIncome(Income &income)
{
    incomesVector.push_back(income);
    isIncomesVectorSortedByDate = false;

    incomesXML.AddElem("income");
    incomesXML.IntoElem();
    incomesXML.AddElem("incomeID", income.getIncomeID());
    incomesXML.AddElem("userID", income.getUserID());
    incomesXML.AddElem("date", income.getDate());
    incomesXML.AddElem("item", income.getItem());
    incomesXML.AddElem("amount", typeConversion.doubleToString(income.getAmount()));
    incomesXML.OutOfElem();
    incomesXML.Save(incomesFileName);
}

void IncomesFile::loadIncomesToVector()
{
    Income newIncome;
    while(incomesXML.FindElem("income"))
    {
        incomesXML.IntoElem();

        incomesXML.FindElem("incomeID");
        newIncome.setIncomeID(atoi(incomesXML.GetData().c_str()));

        incomesXML.FindElem("userID");
        newIncome.setUserID(atoi(incomesXML.GetData().c_str()));

        incomesXML.FindElem("date");
        newIncome.setDate(typeConversion.stringDateToInt(incomesXML.GetData().c_str()));

        incomesXML.FindElem("item");
        newIncome.setItem(incomesXML.GetData());

        incomesXML.FindElem("amount");
        newIncome.setAmount(atof(incomesXML.GetData().c_str()));

        incomesXML.OutOfElem();

        incomesVector.push_back(newIncome);
    }
}

void IncomesFile::sortIncomesByDate()
{
    sort(incomesVector.begin(), incomesVector.end(), [ ](Income& income1, Income& income2)
    {
        return income1.getDate() < income2.getDate();
    });

    isIncomesVectorSortedByDate = true;
}
