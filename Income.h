#ifndef Income_h
#define Income_h
#include <iostream>

using namespace std;

class Income
{
    int incomeID;
    int userID;
    int intDate;
    string stringDate;
    string item;
    double amount;


public:
    Income();
    void setIncomeID(int i);
    void setUserID(int userID);
    void setIntDate(int intDate);
    void setStringDate(string stringDate);
    void setItem(string item);
    void setAmount(double amount);
    int getIncomeID();
    int getIntDate();
    int getUserID();
    string getStringDate();
    string getItem();
    double getAmount();

};

#endif
