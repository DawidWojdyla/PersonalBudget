#include <iostream>
#include <windows.h>
#include "Users.h"

using namespace std;


Users::Users()
{
    currentUserID = 0;
}
int Users::getCurrentUserID()
{
    return currentUserID;
}
void Users::registration()
{
    system("cls");
    string name, surname, username, password;

    cout << "Please enter your username: ";
    cin >> username;

    if(usersFile.checkUsername(username))
    {
        cout << "Unfortunately, the username already exists...";
        Sleep(1000);
    }
    else
    {
        cout << "Please enter your name: ";
        cin >> name;
        cout << "Please enter your surname: ";
        cin >> surname;
        cout << "Set your password: ";
        cin >> password;
        int userID = usersFile.nextUserID();
        User newUser(userID, username, password, name, surname);
        usersFile.addNewUser(newUser);
        system("cls");
        cout << "\tRegistration was successful, you can log in now";
        Sleep(1800);
    }
}

bool Users::login()
{
    system("cls");
    string username, password;

    cout << "Please enter your username: ";
    cin >> username;

    if(usersFile.checkUsername(username))
    {
        for(int i = 2; i >= 0; i--)
        {
            cout << "Please enter the password: ";
            cin >> password;
            if(usersFile.currentUserIterator->getPassword() == password)
            {
                system("cls");

                currentUserID = usersFile.currentUserIterator->getUserID();

                cout << "\n\tLogin has completed successfully" << endl;
                cout << "\n\n\t\tWelcome " << username << " :)" << endl;

                Sleep(2000);
                return true;
            }
            else cout << "Password is not valid (you have " << i << " attempts left)" << endl;
        }
        Sleep(1000);
        return false;
    }
    else cout << "The username does not exist";
    Sleep(1000);
    return false;
}
bool Users::logOff()
{
    char choice;
    cout << "Are you sure to log off? Press 'y' to confirm: ";
    cin >> choice;
    if(choice == 'y')
    {
        currentUserID = 0;
        usersFile.resetCurrentUserIterator();
        cout << "\nYou have been logged out";
        return true;
    }
    else cout << "\nYou have not been logged off";
    return false;
}
void Users::changePassword()
{
    system("cls");
    string newPassword;
    cout << "Please enter a new password: ";
    cin >> newPassword;

    usersFile.changePassword(newPassword);
    cout << endl << "\nPassword has been changed";
    Sleep(1500);
}

