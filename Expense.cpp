#include "Expense.h"


Expense::Expense()
{
    expenseID   = 0;
    userID      = 0;
    intDate     = 0;
    stringDate  = "";
    item        = "";
    amount      = 0;
}
void Expense::setExpenseID(int expenseID)
{
    this->expenseID = expenseID;
}
void Expense::setUserID(int userID)
{
    this->userID = userID;
}
void Expense::setIntDate(int intDate)
{
    this->intDate = intDate;
}
void Expense::setStringDate(string stringDate)
{
    this->stringDate = stringDate;
}
void Expense::setItem(string item)
{
    this->item = item;
}
void Expense::setAmount(double amount)
{
    this->amount = amount;
}
int Expense::getExpenseID()
{
    return expenseID;
}
int Expense::getUserID()
{
    return userID;
}
int Expense::getIntDate()
{
    return intDate;
}
string Expense::getStringDate()
{
    return stringDate;
}
string Expense::getItem()
{
    return item;
}
double Expense::getAmount()
{
    return amount;
}
