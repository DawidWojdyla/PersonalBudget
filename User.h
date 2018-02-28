#include <iostream>

using namespace std;

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
