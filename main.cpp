#include <iostream>
#include <windows.h>
#include "Users.h"
#include "HomeBudget.h"


using namespace std;

int main()
{
    Users users;
    HomeBudget homeBudget;

    char choice;

    while(true)
    {
        if(users.getCurrentUserID() == 0)
        {
            system("cls");
            cout << "PERSONAL BUDGET" << endl;
            cout << "---------------------" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Exit" << endl;

            cin >> choice;
            cin.sync();
            switch(choice)
            {
            case '1':
                if(users.login())
                homeBudget.setUserID(users.getCurrentUserID());
                break;
            case '2':
                users.registration();
                break;
            case '3':
                exit(0);
            default:
                cout << "\n\tPlease press 1-3";
                Sleep(2200);
                break;
            }
        }
        else
        {
            system("cls");
            cout << "\tPERSONAL BUDGET" << endl;
            cout << "---------------------" << endl;
            cout << "1. Add new income" << endl;
            cout << "2. Add new expense" << endl;
            cout << "3. Show the balance of the current month" << endl;
            cout << "4. Show the balance of the previous month" << endl;
            cout << "5. Show a balance of selected period" << endl;
            cout << "6. Change your password" << endl;
            cout << "7. Log off" << endl;
            cout << "8. Exit" << endl;

            cin >> choice;
            cin.sync();
            switch(choice)
            {
            case '1': homeBudget.addNewIncome();

                break;
            case '2': homeBudget.addNewExpense();

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                users.changePassword();
                break;
            case '7':
                 if(users.logOff())
                    homeBudget.setUserID(0);
                break;
            case '8':
                exit(0);
                break;
            default:
            {
                cout << "\n\tPlease press 1-8";
                Sleep(2200);
                break;
            }
            }
        }
    }
    return 0;
}
