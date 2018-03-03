#ifndef UsersFile_h
#define UsersFile_h
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"

using namespace std;


class UsersFile
{
    friend class Users;
    string usersFileName;
    CMarkup usersXML;
    vector <User> usersVector;
    vector <User>::iterator currentUserIterator;
public:
    UsersFile();
    public:
    void loadUsersToVector();
    void addNewUser(User &newUser);
    void changePassword(string newPassword);
    int nextUserID();
    bool checkUsername(string username);
    void resetCurrentUserIterator();
};

#endif
