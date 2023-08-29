#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "user.h"
#include "task.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

const string server = "127.0.0.1:3306";
const string username = "root@localhost";
const string password = "Z1x2c3u4b5n6m728";

sql::Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::PreparedStatement* pstmt;
sql::ResultSet* result;

void connect_db() {
    try
    {
        cout << "Laczenie z serwerem..." << endl;
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Nie mozna polaczyc z serwerem. Typ bledu: " << e.what() << endl;
        exit(1);
    }

    con->setSchema("task_manager_db");
}

void create_user_table() {
    connect_db();
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE users(id serial PRIMARY KEY, name VARCHAR(50), last_name VARCHAR(50), email VARCHAR(50), password VARCHAR(50)");
    cout << "Utworzono tabelê uzytkownikow." << endl;
    delete stmt;
    delete con;
}

void create_task_table() {
    connect_db();
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE tasks(id serial PRIMARY KEY, title VARCHAR(50), desc VARCHAR(50), init_date VARCHAR(50), exp_date VARCHAR(50)");
    cout << "Utworzono tabelê zadan." << endl;
    delete stmt;
    delete con;
}

void add_user_to_db(string ID, string name, string lastName, string email, string password) {
    connect_db();
    pstmt = con->prepareStatement("SELECT * FROM users");
    result = pstmt->executeQuery();

    const string userID = result->getString(0).c_str();
    const string userEmail = result->getString(3).c_str();

    while (result->next())
    {
        if (userID == ID && userEmail == email)
        {
            cout << "Uzytkownik z identycznym adresem e-mail juz istnieje." << endl;
            break;
        }
        else
        {
            pstmt = con->prepareStatement("INSERT INTO users(name, last_name, email, password) VALUES(" + name + ", " + lastName + ", " + email + ", " + password + ")");
            pstmt->execute();
            cout << "Pomyslnie zarejestrowano uzytkownika." << endl;
            break;
        }
    }
    delete result;
    delete pstmt;
    delete con;
}

User User::get_user_from_db(string email, string password)
{
    User user;
    connect_db();
    pstmt = con->prepareStatement("SELECT * FROM users");
    result = pstmt->executeQuery();
    while (result->next()) {
        if (result->getString(3).c_str() == email && result->getString(4).c_str() == password)
        {
            cout << "Zalogowano pomyslnie" << endl;
            user.ID = result->getString(0).c_str();
            user.Name = result->getString(1).c_str();
            user.LastName = result->getString(2).c_str();
            user.Email = result->getString(3).c_str();
            user.Password = result->getString(4).c_str();
            break;
        }
        cout << "Nie znaleziono uzytkownika. Sprobuj ponownie." << endl;
    }
    delete result;
    delete pstmt;
    delete con;
    delete& user;
    return user;
}

void update_user_password(string ID, string newPassword)
{
    connect_db();
    pstmt = con->prepareStatement("UPDATE users SET password = " + newPassword + " WHERE id = " + ID + "");
    pstmt->executeQuery();
    delete con;
    delete pstmt;
}

void delete_user_from_db(string ID, string password)
{
    connect_db();
    pstmt = con->prepareStatement("DELETE From users WHERE id = " + ID + ", password = " + password + "");
    result = pstmt->executeQuery();
    cout << "Usunieto uzytkownika" << endl;
    delete pstmt;
    delete con;
    delete result;
}

void create_new_task(string userID, string title, string desc, string initDate, string expDate)
{
    connect_db();
    pstmt = con->prepareStatement("INSERT INTO tasks(user_id, title, desc, init_date, exp_date) VALUES(" + userID + ", " + title + ", " + desc + ", " + initDate + ", " + expDate + ")");
    delete pstmt;
    delete con;
}

Task Task::get_task_from_db(string userID, string title)
{
    Task task;
    connect_db();
    pstmt = con->prepareStatement("SELECT * FROM tasks WHERE user_id = " + userID + ";");
    result = pstmt->executeQuery();

    while (result->next())
    {
        if (result->getString(1).c_str() == userID && result->getString(2).c_str() == title)
        {
            task.ID = result->getInt(0);
            task.UserID = result->getString(1).c_str();
            task.Title = result->getString(2).c_str();
            task.Desc = result->getString(3).c_str();
            task.InitDate = result->getString(4).c_str();
            task.ExpDate = result->getString(5).c_str();
            break;
        }
    }
    delete result;
    delete pstmt;
    delete con;
    return task;
}

void Task::get_all_tasks(string userID)
{
    connect_db();
    Task task;
    vector <Task> tasks;
    unsigned int tasks_vec_size = tasks.size();

    pstmt = con->prepareStatement("SELECT * FROM tasks WHERE user_id = " + userID + ";");
    result = pstmt->executeQuery();
    while (result->next())
    {
        task.ID = result->getInt(0);
        task.UserID = result->getString(1).c_str();
        task.Title = result->getString(2).c_str();
        task.Desc = result->getString(3).c_str();
        task.InitDate = result->getString(4).c_str();
        task.ExpDate = result->getString(5).c_str();
        tasks.push_back(task);
    }
    cout << "# Zadania do wykonania #" << endl;
    for (unsigned int i = 0; i < tasks_vec_size; i++)
    {
        cout << "--------------------------------" << endl;
        cout << "Tytul zadania: " << tasks[i].Title << endl;
        cout << "Opis: " << tasks[i].Desc << endl;
        cout << "Data rozpoczecia: " << tasks[i].InitDate << endl;
        cout << "Data zakonczenia:" << tasks[i].ExpDate << endl;
        cout << "--------------------------------" << endl;
    }
    delete result;
    delete pstmt;
    delete con;
    delete &task;
}

void update_task(string title, string fieldToUpdate, string value)
{
    connect_db();
    pstmt = con->prepareStatement("UPDATE tasks set " + fieldToUpdate + " = " + value + " WHERE title = " + title + ";");
    delete pstmt;
    delete con;
}

void delete_task(string userID, string title)
{
    connect_db();
    pstmt = con->prepareStatement("DELETE FROM tasks WHERE id = " + userID + ";");
    result = pstmt->executeQuery();
    cout << "Pomyslnie usunieto zadanie" << endl;

    delete pstmt;
    delete con;
    delete result;
}
