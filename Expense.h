#ifndef Expense_h
#define Expense_h
#include <iostream>

using namespace std;

class Expense
{
    int expenseID;
    int userID;
    int date;
    string item;
    double amount;

public:
    Expense();
    void setExpenseID(int ExpenseID);
    void setUserID(int userID);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
    int getExpenseID();
    int getDate();
    int getUserID();
    string getItem();
    double getAmount();
};

#endif
