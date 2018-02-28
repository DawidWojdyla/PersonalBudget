#include <iostream>
#include "User.h"

using namespace std;


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

