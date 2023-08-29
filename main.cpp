#include <iostream>
#include "user.h"
#include "admin.h"
#include "task.h"
using namespace std;

bool is_input_valid(int option)
{
    if (option != 0 || isdigit(option)) return true;
    return false;
}

int main() {
    User user;
    string s = "";
    char x = '0';
    int option;
    do {
        do {
            cout << "** System do zarzadzania zadaniami **" << endl;
            cout << "Wybierz opcje:\n1 - Logowanie\n2 - Rejestracja\n3 - Wyjscie z programu" << endl;
            cin >> option;
            if (!is_input_valid(option)) cerr << "Nieprawidlowa wartosc. Sprobuj ponownie." << endl;
        } while (!is_input_valid(option));
            switch (option) {
            case 1:
                user.Login();
                break;
            case 2:
                user.Register();
                break;
            case 3:
                cout << "Czy napewno chcesz zakonczyc program? (T/N)";
                cin >> x;
                if (x == 'T') {
                    cout << "\nProgram zakonczy³ swoje dzialanie." << endl;
                    s = "stop";
                    break;
                }
                s = "";
                break;
            default:
                cout << "Nie rozpoznano polecenia" << endl;
                break;
            };
    } while (s != "stop");
    delete &user;
    system("pause");
    return 0;
}