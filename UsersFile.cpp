#include <iostream>
#include "UsersFile.h"

using namespace std;

UsersFile::UsersFile()
{
    usersFileName = "users.xml";
    usersXML.Load(usersFileName);
    loadUsersToVector();
    currentUserIterator = usersVector.begin();
}
void UsersFile::addNewUser(User &newUser)
{
    usersVector.push_back(newUser);
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
int UsersFile::nextUserID()
{
    if(usersVector.empty())
        return 1;
    else return usersVector.back().getUserID() + 1;
}
void UsersFile::changePassword(string newPassword)
{
    currentUserIterator->setPassword(newPassword);

    usersXML.ResetPos();
    while(usersXML.FindElem("user"))
    {
        usersXML.FindChildElem("userID");
        if(atoi(usersXML.GetChildData().c_str()) == currentUserIterator->getUserID())
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

void UsersFile::loadUsersToVector()
{
    User newUser;
    while(usersXML.FindElem("user"))
    {
        usersXML.IntoElem();
        usersXML.FindElem("userID");
        newUser.setUserID(atoi(usersXML.GetData().c_str()));
        usersXML.FindElem("username");
        newUser.setUsername(usersXML.GetData());
        usersXML.FindElem("password");
        newUser.setPassword(usersXML.GetData());
        usersXML.FindElem("name");
        newUser.setName(usersXML.GetData());
        usersXML.FindElem("surname");
        newUser.setSurname(usersXML.GetData());
        usersXML.OutOfElem();
        usersVector.push_back(newUser);
    }
}

bool UsersFile::checkUsername(string username)
{
    for(currentUserIterator = usersVector.begin(); currentUserIterator != usersVector.end(); ++currentUserIterator)
        if(currentUserIterator->getUsername() == username)
            return true;
    return false;
}

void UsersFile::resetCurrentUserIterator()
{
    currentUserIterator = usersVector.begin();
}
