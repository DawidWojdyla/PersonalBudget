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
    system("cls");
    double totalIncome, totalExpenses;

    cout << "Incomes:" << endl;
    totalIncome = incomes.showIncomesOfCurrentMonth();

    cout <<"\nExpenses:" << endl;
    totalExpenses = expenses.showExpensesOfCurrentMonth();

    cout << "\nTotal income:   " << setw(10) << right << totalIncome << endl;
    cout << "Total expenses: " << setw(10) << right << totalExpenses << endl;
    cout << "Balance:        " << setw(10) << right << totalIncome - totalExpenses << endl;
    system("pause");
}
void HomeBudget::showBalanceOfPreviousMonth()
{
    system("cls");
    double totalIncome, totalExpenses;

    cout << "Incomes:" << endl;
    totalIncome = incomes.showIncomesOfPreviousMonth();

    cout <<"\nExpenses:" << endl;
    totalExpenses = expenses.showExpensesOfPreviousMonth();

    cout << "\nTotal income:   " << setw(10) << right << totalIncome << endl;
    cout << "Total expenses: " << setw(10) << right << totalExpenses << endl;
    cout << "Balance:        " << setw(10) << right << totalIncome - totalExpenses << endl << endl;
    system("pause");

}
void HomeBudget::showBalanceOfSelectedPeriod()
{
    system("cls");
    double totalIncome, totalExpenses;
    string dateFrom, dateTo;

    cout << "Please enter the date you'd like to see the balance from: " << endl;
    cout << "(only yyyy-mm-dd format is accepted, e.g. 2018-02-17): " << endl;
    do
    {
        cin >> dateFrom;
        if(!incomes.dateOperator.validateDate(dateFrom))
            cout << "The date is incorrect, please enter a proper date (e.g. 2015-02-27) :" << endl;
        else break;
    }
    while(!incomes.dateOperator.validateDate(dateFrom));

    cout << "Please enter the date you'd like to see the balance to: " << endl;
    cout << "(only yyyy-mm-dd format is accepted, e.g. 2018-02-17): " << endl;
    do
    {
        cin >> dateTo;
        if(!incomes.dateOperator.validateDate(dateTo))
            cout << "The date is incorrect, please enter a proper date (yyyy-mm-dd format) : " << endl;
        else break;
    }
    while(!incomes.dateOperator.validateDate(dateTo));

    system("cls");

    cout << "Incomes:" << endl;
    totalIncome = incomes.showIncomesOfSelectedPeriod(dateFrom, dateTo);

    cout <<"\nExpenses:" << endl;
    totalExpenses = expenses.showExpensesOfSelectedPeriod(dateFrom, dateTo);

    cout << "\nTotal income:   " << setw(10) << right << totalIncome << endl;
    cout << "Total expenses: " << setw(10) << right << totalExpenses << endl;
    cout << "Balance:        " << setw(10) << right << totalIncome - totalExpenses << endl << endl;
    system("pause");
}
