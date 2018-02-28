#include <iostream>
#include "UsersFile.h"
#include "Markup.h"

using namespace std;


UsersFile::UsersFile()
{
    usersFileName = "users.xml";
    usersXML.Load(usersFileName);
    loadUsersToVector();
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
