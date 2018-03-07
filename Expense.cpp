#include "Expense.h"


Expense::Expense()
{
    expenseID   = 0;
    userID      = 0;
    date     = 0;
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
void Expense::setDate(int date)
{
    this->date = date;
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
int Expense::getDate()
{
    return date;
}
string Expense::getItem()
{
    return item;
}
double Expense::getAmount()
{
    return amount;
}
