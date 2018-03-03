#include "HomeBudget.h"

HomeBudget::HomeBudget()
{
}

void HomeBudget::setUserID(int userID)
{
    incomes.setUserID(userID);
    expenses.setUserID(userID);
}
void HomeBudget::addNewIncome()
{
    incomes.addNewIncome();
}
void HomeBudget::addNewExpense()
{
    expenses.addNewExpense();
}
void HomeBudget::showBalanceOfCurrentMonth()
{

}
void HomeBudget::showBalanceOfPreviousMonth()
{

}
void HomeBudget::showBalanceOfSelectedPeriod()
{

}
