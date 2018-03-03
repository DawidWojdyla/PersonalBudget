#ifndef Expense_h
#define Expense_h
#include <iostream>

using namespace std;

class Expense
{
    int expenseID;
    int userID;
    int intDate;
    string stringDate;
    string item;
    double amount;

public:
    Expense();
    void setExpenseID(int ExpenseID);
    void setUserID(int userID);
    void setIntDate(int intDate);
    void setStringDate(string stringDate);
    void setItem(string item);
    void setAmount(double amount);
    int getExpenseID();
    int getIntDate();
    int getUserID();
    string getStringDate();
    string getItem();
    double getAmount();
};

#endif
