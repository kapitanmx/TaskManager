#pragma once
#include <iostream>
using namespace std;

class User {
    private:
        string ID, Name, LastName, Email, Password;
    public:
        User();
        User(string name, string lastName, string email, string password);
        void Login();
        void Register();
        User get_user_from_db(string, string);
        void Update(string id, string option, string value);
        void Delete(string id);
        ~User();
};