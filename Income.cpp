#include "Income.h"


Income::Income()
{
    incomeID    = 0;
    userID      = 0;
    date     = 0;
    item        = "";
    amount      = 0;
}
void Income::setIncomeID(int incomeID)
{
    this->incomeID = incomeID;
}
void Income::setUserID(int userID)
{
    this->userID = userID;
}
void Income::setDate(int date)
{
    this->date = date;
}
void Income::setItem(string item)
{
    this->item = item;
}
void Income::setAmount(double amount)
{
    this->amount = amount;
}
int Income::getIncomeID()
{
    return incomeID;
}
int Income::getUserID()
{
    return userID;
}
int Income::getDate()
{
    return date;
}
string Income::getItem()
{
    return item;
}
double Income::getAmount()
{
    return amount;
}

