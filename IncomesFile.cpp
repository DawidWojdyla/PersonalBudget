#include "IncomesFile.h"

IncomesFile::IncomesFile()
{
    incomesFileName = "incomes.xml";
    incomesXML.Load(incomesFileName);
    loadIncomesToVector();
    incomesVectorSortedByDate = false;
}

void IncomesFile::addIncome(Income &income)
{
    incomesVector.push_back(income);
    incomesVectorSortedByDate = false;

    incomesXML.AddElem("income");
    incomesXML.IntoElem();
    incomesXML.AddElem("incomeID", income.getIncomeID());
    incomesXML.AddElem("userID", income.getUserID());
    incomesXML.AddElem("date", income.getStringDate());
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
        newIncome.setStringDate(incomesXML.GetData());
        newIncome.setIntDate(typeConversion.stringDateToInt(newIncome.getStringDate()));

        incomesXML.FindElem("item");
        newIncome.setItem(incomesXML.GetData());

        incomesXML.FindElem("amount");
        newIncome.setAmount(atof(incomesXML.GetData().c_str()));

        incomesXML.OutOfElem();

        incomesVector.push_back(newIncome);
    }

}
