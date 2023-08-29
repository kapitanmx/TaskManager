#pragma once
#include <iostream>
using namespace std;

class Task {
private:
    string ID, UserID, Title, Desc, InitDate, ExpDate;
public:
    Task();
    Task(string id, string userID, string title, string desc, string initDate, string expDate);
    Task get_task_from_db(string, string);
    void get_all_tasks(string);
    void CreateTask(string);
    void UpdateTask(string);
    void DisplayTask(string, string);
    void DisplayAllTasks(string);
    void DeleteTask(string, string);
    ~Task();
};