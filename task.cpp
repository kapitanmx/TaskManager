#include "task.h"
//#include "db.h"
#include <iostream>
#include <vector>
using namespace std;

Task::Task() {}

Task::Task(string id, string userID, string title, string desc, string initDate, string expDate)
    :ID(id), UserID(userID), Title(title), Desc(desc), InitDate(initDate), ExpDate(expDate)
{}

bool is_input_valid(string param)
{
    if (param == "") return false;
    return true;
}

void input_checker(string param)
{
    is_input_valid(param) ? cerr << "Nieprawidlowa wartosc. Sprobuj ponownie." << endl : cout << endl;
}

void Task::CreateTask(string UserID)
{
    Task task;
    do {
        cout << "Podaj tytul zadania: " << endl;
        cin >> task.Title;
        input_checker(task.Title);
    } while (!is_input_valid(task.Title));
    do {
        cout << "Podaj opis: " << endl;
        cin >> task.Desc;
        input_checker(task.Desc);
    } while (!is_input_valid(task.Desc));
    do {
        cout << "\nPodaj date rozpoczecia: " << endl;
        cin >> task.InitDate;
        input_checker(task.InitDate);
    } while (!is_input_valid(task.InitDate));
    do {
        cout << "\nPodaj date zakonczenia: " << endl;
        cin >> task.ExpDate;
        input_checker(task.ExpDate);
    } while (!is_input_valid(task.ExpDate));
    //create_new_task(UserID, task.Title, task.Desc, task.InitDate, task.ExpDate);
}

void Task::DisplayTask(string UserID, string title)
{
    Task task;
    //task = get_task_from_db(UserID, title);
    cout << "+------------------+" << endl;
    cout << "Tytul: " << task.Title << endl;
    cout << "Opis: " << task.Desc << endl;
    cout << "Data rozpoczecia: " << task.InitDate << endl;
    cout << "Data zakonczenia: " << task.ExpDate << endl;
    cout << "+------------------+";
    delete &task;
}

void Task::DisplayAllTasks(string UserID)
{
    //get_all_tasks(UserID);
}

void Task::UpdateTask(string UserID)
{
    Task task;
    string title;
    int choice;
    cout << "** Edycja zadania **" << endl;
    do {
        cout << "Podaj tytul zadania, ktore chcesz edytowac: " << endl;
        cin >> title;
        input_checker(title);
    } while (!is_input_valid(title));
    cout << "Wybierz opcje:\n1 - zmien tytul\n2 - zmien opis\n3 - zmien date rozpoczecia\n4 - zmien date zakonczenia" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        do {
            cout << "Wprowadz nowy tytul: " << endl;
            cin >> task.Title;
            input_checker(task.Title);
        } while (!is_input_valid(task.Title));
        //update_task(title, "title", task.Title);
        break;
    case 2:
        do {
            cout << "Wprowadz nowy opis: " << endl;
            cin >> task.Desc;
            input_checker(task.Desc);
        } while (!is_input_valid(task.Desc));
        //update_task(title, "desc", task.Desc);
        break;
    case 3:
        do {
            cout << "Wprowadz nowa date rozpoczecia: " << endl;
            cin >> task.InitDate;
            input_checker(task.InitDate);
        } while (!is_input_valid(task.InitDate));
        //update_task(title, "init_date", task.InitDate);
        break;
    case 4:
        do {
            cout << "Wprowadz nowa date zakonczenia: " << endl;
            cin >> task.ExpDate;
            input_checker(task.ExpDate);
        } while (!is_input_valid(task.ExpDate));
        //update_task(title, "exp_date", task.ExpDate);
        break;
    default:
        cout << "Nie rozpoznano polecenia. Sprobuj ponownie.";
        break;
    };
    delete &task;
    system("pause");
}

void Task::DeleteTask(string userID, string title)
{
    do {
        cout << "** Usun zadanie **" << endl;
        cout << "Podaj tytul zadania: ";
        cin >> title;
        input_checker(title);
    } while (!is_input_valid(title));
    //delete_task(userID, title);
}

Task::~Task()
{
    cout << "Destruktor klasy task" << endl;
}