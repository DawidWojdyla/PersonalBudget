#include "Amount.h"

Amount::Amount()
{
    amountLength = 0;
    numberOfDots = 0;
}

bool Amount::checkAmount(string &amount)
{
    if(amount[0] == '.' || amount[0] == ',')
        amount = "0" + amount;

    if(amount[0] < '0' || amount[0] > '9')
        return false;

    amount = commasToDots(amount);

    if(numberOfDots > 1)
        return false;

    for(int i = 0; i < amountLength; i++)
        if((amount[i] < '0' || amount[i] > '9') && amount[i] != '.')
            return false;

    return true;
}
string Amount::commasToDots(string amount)
{
    amountLength = amount.length();
    numberOfDots = 0;
    for(int i = 0; i < amountLength; i++)
    {
        if(amount[i] == ',' || amount[i] == '.')
        {
            amount[i] = '.';
            numberOfDots++;
        }
    }
    return amount;
}
