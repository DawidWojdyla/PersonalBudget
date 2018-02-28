#include <iostream>
#include "UsersFile.h"

using namespace std;

class Users
{
    int currentUserID;
    UsersFile usersFile;
public:
    Users();
    void registration();
    bool login();
    bool logOff();
    int getCurrentUserID();
    void changePassword();
private:
    void addNewUser(string name, string surname, string username, string password);
};
