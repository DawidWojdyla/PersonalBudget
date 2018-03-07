#ifndef Income_h
#define Income_h
#include <iostream>

using namespace std;

class Income
{
    int incomeID;
    int userID;
    int date;
    string item;
    double amount;

public:
    Income();
    void setIncomeID(int incomeID);
    void setUserID(int userID);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
    int getIncomeID();
    int getDate();
    int getUserID();
    string getStringDate();
    string getItem();
    double getAmount();

};

#endif
