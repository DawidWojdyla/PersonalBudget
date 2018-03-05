#include "ExpensesFile.h"

ExpensesFile::ExpensesFile()
{
    expensesFileName = "expenses.xml";
    expensesXML.Load(expensesFileName);
    loadExpensesToVector();
    expensesVectorSortedByDate = false;
}

void ExpensesFile::addExpense(Expense &expense)
{
    expensesVector.push_back(expense);
    expensesVectorSortedByDate = false;

    expensesXML.AddElem("expense");
    expensesXML.IntoElem();
    expensesXML.AddElem("expenseID", expense.getExpenseID());
    expensesXML.AddElem("userID", expense.getUserID());
    expensesXML.AddElem("date", expense.getStringDate());
    expensesXML.AddElem("item", expense.getItem());
    expensesXML.AddElem("amount", typeConversion.doubleToString(expense.getAmount()));
    expensesXML.OutOfElem();
    expensesXML.Save(expensesFileName);
}

void ExpensesFile::loadExpensesToVector()
{
    Expense newExpense;
    while(expensesXML.FindElem("expense"))
    {
        expensesXML.IntoElem();
        expensesXML.FindElem("expenseID");
        newExpense.setExpenseID(atoi(expensesXML.GetData().c_str()));

        expensesXML.FindElem("userID");
        newExpense.setUserID(atoi(expensesXML.GetData().c_str()));

        expensesXML.FindElem("date");
        newExpense.setStringDate(expensesXML.GetData());
        newExpense.setIntDate(typeConversion.stringDateToInt(expensesXML.GetData()));

        expensesXML.FindElem("item");
        newExpense.setItem(expensesXML.GetData());

        expensesXML.FindElem("amount");
        newExpense.setAmount(atof(expensesXML.GetData().c_str()));

        expensesXML.OutOfElem();

        expensesVector.push_back(newExpense);
    }
}
