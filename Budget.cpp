#include "Budget.h"
#include "Markup.h"
#include <windows.h>
#include <sstream>


string TypeConversion::intToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

User::User()
{
    userID = 0;
    username = "";
    password = "";
    name = "";
    surname = "";
}
void User::setUserID(int userID)
{
    this->userID = userID;
}
void User::setUsername(string username)
{
    this->username = username;
}
void User::setPassword(string password)
{
    this->password = password;
}
void User::setName(string name)
{
    this->name = name;
}
void User::setSurname(string surname)
{
    this->surname = surname;
}
int User::getUserID()
{
    return userID;
}
string User::getUsername()
{
    return username;
}
string User::getPassword()
{
    return password;
}
string User::getName()
{
    return name;
}
string User::getSurname()
{
    return surname;
}


UsersFile::UsersFile()
{
    usersFileName = "users.xml";
    usersXML.Load(usersFileName);
}
void UsersFile::addNewUser(User &newUser)
{
    usersXML.AddElem("user");
    usersXML.IntoElem();
    usersXML.AddElem("userID", newUser.getUserID());
    usersXML.AddElem("username", newUser.getUsername());
    usersXML.AddElem("password", newUser.getPassword());
    usersXML.AddElem("name", newUser.getName());
    usersXML.AddElem("surname", newUser.getSurname());
    usersXML.OutOfElem();
    usersXML.Save(usersFileName);
}
void UsersFile::changePassword(string newPassword, int userID)
{
    usersXML.ResetPos();
    while(usersXML.FindElem("user"))
    {
        usersXML.FindChildElem("userID");
        if(usersXML.GetChildData() == typeConversion.intToString(userID))
        {
            if(usersXML.FindChildElem("password"))
            {
                usersXML.SetChildData(newPassword);
                usersXML.Save(usersFileName);
                break;
            }
        }
    }
}


Users::Users()
{
    currentUserID = 0;
    loadUsersToVector();
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

    for(vector <User>::iterator itr = usersVector.begin(), theEnd = usersVector.end(); itr !=theEnd; ++itr)
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

    if(usersVector.empty())
        newUser.setUserID(1);
    else
        newUser.setUserID(usersVector.back().getUserID() + 1);

    newUser.setName(name);
    newUser.setSurname(surname);
    newUser.setUsername(username);
    newUser.setPassword(password);

    usersVector.push_back(newUser);
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
    int numberOfUsers = usersVector.size();
    int userPosition;

    for(int i = 0; i < numberOfUsers; i++)
    {
        if(username == usersVector[i].getUsername())
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
            if(password == usersVector[userPosition].getPassword())
            {
                currentUserID = usersVector[userPosition].getUserID();
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
    int numberOfUsers = usersVector.size();

    for(int i = 0; i < numberOfUsers; i++)
        if(usersVector[i].getUserID() == currentUserID)
        {
            usersVector[i].setPassword(newPassword);
            usersFile.changePassword(newPassword, currentUserID);
            cout << endl << "\nPassword has been changed";
            break;
        }
    Sleep(1800);
}
void Users::loadUsersToVector()
{
    User newUser;
    while(usersFile.usersXML.FindElem("user"))
    {
        usersFile.usersXML.IntoElem();
        usersFile.usersXML.FindElem("userID");
        newUser.setUserID(atoi(usersFile.usersXML.GetData().c_str()));
        usersFile.usersXML.FindElem("username");
        newUser.setUsername(usersFile.usersXML.GetData());
        usersFile.usersXML.FindElem("password");
        newUser.setPassword(usersFile.usersXML.GetData());
        usersFile.usersXML.FindElem("name");
        newUser.setName(usersFile.usersXML.GetData());
        usersFile.usersXML.FindElem("surname");
        newUser.setSurname(usersFile.usersXML.GetData());
        usersFile.usersXML.OutOfElem();
        usersVector.push_back(newUser);
    }
}



