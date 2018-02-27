#include <iostream>
#include <vector>
#include "Markup.h"

using namespace std;


class TypeConversion
{
public:
    string intToString(int number);
};

class User
{
    int userID;
    string username;
    string password;
    string name;
    string surname;

public:
    User();
    void setUserID(int userID);
    void setUsername(string username);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
    int getUserID();
    string getUsername();
    string getPassword();
    string getName();
    string getSurname();
};

class UsersFile
{
    string usersFileName;
    TypeConversion typeConversion;
public:
    CMarkup usersXML;
    UsersFile();
    void addNewUser(User &newUser);
    void changePassword(string newPassword, int userID);
};

class Users
{
    int currentUserID;
    vector <User> usersVector;
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
    void loadUsersToVector();
};



