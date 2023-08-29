#pragma once
#include "user.h"
#include <iostream>
using namespace std;

class Admin : public User {
private:
    string ID, Name, Email, Password;
public:
    Admin(string id, string name, string email, string password);
    void EditAdmin(string id, string option, string value);
    void DeleteAdmin(string id);
    friend void EditUser(string userID);
    friend void DeleteUser(string userID);
    ~Admin();
};