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
    bool doesTheUsernameAlreadyExist = false;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your surname: ";
    cin >> surname;
    cout << "Please enter your username: ";
    cin >> username;

    for(vector <User>::iterator itr = usersFile.usersVector.begin(), theEnd = usersFile.usersVector.end(); itr !=theEnd; ++itr)
    {
        if(itr->getUsername() == username)
        {
            doesTheUsernameAlreadyExist = true;
            break;
        }
    }
    if(doesTheUsernameAlreadyExist) cout << "Unfortunately, the username already exists...";
    else
    {
        cout << "Set your password: ";
        cin >> password;
        addNewUser(name, surname, username, password);
        system("cls");
        cout << "\tRegistration was successful, you can log in now";
        Sleep(1800);
    }
}
void Users::addNewUser(string name, string surname, string username, string password)
{
    User newUser;

    if(usersFile.usersVector.empty())
        newUser.setUserID(1);
    else
        newUser.setUserID(usersFile.usersVector.back().getUserID() + 1);

    newUser.setName(name);
    newUser.setSurname(surname);
    newUser.setUsername(username);
    newUser.setPassword(password);

    usersFile.usersVector.push_back(newUser);
    usersFile.addNewUser(newUser);
}
bool Users::login()
{
    system("cls");
    string username, password;
    bool loggedIn = false;
    cout << "Please enter your username: ";
    cin >> username;
    bool doesTheUsernameAlreadyExist = false;
    int numberOfUsers = usersFile.usersVector.size();
    int userPosition;

    for(int i = 0; i < numberOfUsers; i++)
    {
        if(username == usersFile.usersVector[i].getUsername())
        {
            doesTheUsernameAlreadyExist = true;
            userPosition = i;
            break;
        }
    }
    if(doesTheUsernameAlreadyExist)
    {
        for(int i = 2; i >= 0; i--)
        {
            cout << "Please enter the password: ";
            cin >> password;
            if(password == usersFile.usersVector[userPosition].getPassword())
            {
                currentUserID = usersFile.usersVector[userPosition].getUserID();
                loggedIn = true;
                system("cls");
                cout << "\n\tLogin has completed successfully" << endl;
                cout << "\n\n\tWelcome " << username << " :)";
                break;
            }
            else cout << "Password is not valid (you have " << i << " attempts left)" << endl;
        }
    }
    else cout << "The username does not exist";
    Sleep(2200);
    return loggedIn;
}
bool Users::logOff()
{
    bool loggedOut = false;
    char choice;
    cout << "Are you sure to log off? Press 'y' to confirm: ";
    cin >> choice;
    if(choice == 'y')
    {
        currentUserID = 0;
        loggedOut = true;
        cout << "\nYou have been logged out";
    }
    else cout << "\nYou have not been logged off";
    return loggedOut;
}
void Users::changePassword()
{
    system("cls");
    string newPassword;
    cout << "Please enter a new password: ";
    cin >> newPassword;
    int numberOfUsers = usersFile.usersVector.size();

    for(int i = 0; i < numberOfUsers; i++)
        if(usersFile.usersVector[i].getUserID() == currentUserID)
        {
            usersFile.usersVector[i].setPassword(newPassword);
            usersFile.changePassword(newPassword, currentUserID);
            cout << endl << "\nPassword has been changed";
            break;
        }
    Sleep(1800);
}

