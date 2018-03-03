#include "Income.h"


Income::Income()
{
    incomeID    = 0;
    userID      = 0;
    intDate     = 0;
    stringDate  = "";
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
void Income::setIntDate(int intDate)
{
    this->intDate = intDate;
}
void Income::setStringDate(string stringDate)
{
    this->stringDate = stringDate;
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
int Income::getIntDate()
{
    return intDate;
}
string Income::getStringDate()
{
    return stringDate;
}
string Income::getItem()
{
    return item;
}
double Income::getAmount()
{
    return amount;
}


