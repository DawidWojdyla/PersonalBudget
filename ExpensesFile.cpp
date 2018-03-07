#include "ExpensesFile.h"

ExpensesFile::ExpensesFile()
{
    expensesFileName = "expenses.xml";
    isExpensesVectorSortedByDate = false;
    expensesXML.Load(expensesFileName);
    loadExpensesToVector();
    sortExpensesByDate();

}
void ExpensesFile::addExpense(Expense &expense)
{
    expensesVector.push_back(expense);
    isExpensesVectorSortedByDate = false;

    expensesXML.AddElem("expense");
    expensesXML.IntoElem();
    expensesXML.AddElem("expenseID", expense.getExpenseID());
    expensesXML.AddElem("userID", expense.getUserID());
    expensesXML.AddElem("date", dateOperator.returnStringDate(expense.getDate()));
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
        newExpense.setDate(typeConversion.stringDateToInt(expensesXML.GetData()));

        expensesXML.FindElem("item");
        newExpense.setItem(expensesXML.GetData());

        expensesXML.FindElem("amount");
        newExpense.setAmount(atof(expensesXML.GetData().c_str()));

        expensesXML.OutOfElem();

        expensesVector.push_back(newExpense);
    }
}

void ExpensesFile::sortExpensesByDate()
{
    sort(expensesVector.begin(), expensesVector.end( ), [ ](Expense& expense1, Expense& expense2)
    {
        return expense1.getDate() < expense2.getDate();
    });
    isExpensesVectorSortedByDate = true;
}
