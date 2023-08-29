#include <iostream>
#include <vector>
#include "user.h"
#include "task.h"
#include "db.h"
using namespace std;


bool input_validation(int param)
{
    if (param <= 0 || !isdigit(param))
    {
        return false;
    }
    return true;
}

User::User() {}

User::User(string name, string lastName, string email, string password)
    : Name(name), LastName(lastName), Email(email), Password(password)
{}

void User::Login()
{
    string taskTitle;
    User user;
    Task task;
    vector <Task> tasks;

    string email, password, newEmail, newPassword, title;
    int option;
    cout << "** Logowanie uzytkownika **" << endl;
    cout << "Podaj adres e-mail: ";
    cin >> email;
    cout << "\nPodaj haslo: ";
    cin >> password;
    user = get_user_from_db(email, password);
    cout << "\nJestes zalogowany jako" << user.Name << " " << user.LastName << endl;
    cout << "Wybierz opcje:\n1 - Edytuj dane uzytkownika\n2 - Zobacz przydzielone zadania\n3 - Wyszukaj zadanie\n4 - Dodaj nowe zadanie\n5 - Edytuj zadanie\n6 - Usun zadanie\n7 - Wyloguj" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "** Edycja danych **" << endl;
        cout << "Wybierz opcje:\n1 - Zmien adres e-mail\n2 - Zmien haslo";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "** Zmiana adresu e-mail" << endl;
            cout << "\nPodaj nowy adres: ";
            cin >> newEmail;
            break;
        case 2:
            cout << "** Zmiana hasla **" << endl;
            cout << "\nPodaj nowe haslo: ";
            cin >> newPassword;
            if (user.Password == newPassword) cerr << "\nNowe i stare haslo musza sie od siebie roznic" << endl;
            update_user_password(user.ID, newPassword);
            break;
        default:
            cout << "Nie rozpoznano polecenia" << endl;
            break;
        }
        break;
    case 2:
        cout << "** Zobacz zadania **" << endl;
        task.get_all_tasks(user.ID);
        break;
    case 3:
        cout << "** Wyszukaj zadanie **" << endl;
        do {
            cout << "Podaj tytul zadania" << endl;
            cin >> title;
            if (title == "") cerr << "Nieprawidlowa wartosc. Sprobuj ponownie." << endl;
        } while (title == "");
        task.DisplayTask(user.ID, title);
        break;
    case 4:
        cout << "** Dodaj nowe zadanie **" << endl;
        task.CreateTask(user.ID);
        break;
    case 5:
        cout << "** Edytuj zadanie **" << endl;
        task.UpdateTask(user.ID);
        break;
    case 6:
        cout << "** Usun zadanie **" << endl;
        task.DeleteTask(user.ID, title);
        break;
    case 7:
        cout << "** Wyloguj **" << endl;
        delete& user;
        delete& task;
        break;
    default:
        cout << "\nNie rozpoznano polecenia. Sprobuj ponownie." << endl;
        break;
    }
 };

void User::Register()
{
    User user;
    string repeatPassword;
    cout << "Rejestracja uzytkownika" << endl;
    cout << "Podaj swoje imie: " << endl;
    cin >> user.Name;
    cout << "Podaj swoje nazwisko: " << endl;
    cin >> user.LastName;
    cout << "Podaj adres email: " << endl;
    cin >> user.Email;
    //if (!is_email_valid(user.Email))
    //{
       // cout << "Adres email jest nieprawidlowy. Sprobuj ponownie" << endl;
    //}
    cout << "Podaj haslo: " << endl;
    cin >> user.Password;
    cout << "Powtorz haslo: " << endl;
    cin >> repeatPassword;
    //if (!is_password_valid(user.Password))
    //{
        //cout << "Haslo powinno zawierac: 8 znakow, w tym przynajmniej jeden znak duzy, jeden maly, cyfre oraz znak specjalny" << endl;
    //}
    if (user.Password != repeatPassword)
    {
        cout << "Podane haslo rozni sie od powtorzonego. Sprobuj ponownie." << endl;
    }
    add_user_to_db(user.ID, user.Name, user.LastName, user.Email, user.Password);
    delete& user;
    system("pause");
}

User::~User()
{
    cout << "Destruktor klasy uzytkownika" << endl;
}