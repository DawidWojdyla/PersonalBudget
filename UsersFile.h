#include <iostream>
#include <vector>
#include "Markup.h"
#include "TypeConversion.h"
#include "User.h"

using namespace std;


class UsersFile
{
    friend class Users;
    string usersFileName;
    vector <User> usersVector;
    CMarkup usersXML;
    TypeConversion typeConversion;
public:
    UsersFile();
    public:
    void loadUsersToVector();
    void addNewUser(User &newUser);
    void changePassword(string newPassword, int userID);
};
