#include <iostream>
#include <regex>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

struct Task {
	string ID;
	string Title;
	string Description;
	string InitDate;
	string ExpDate;
};

struct User
{
	string ID;
	string Name;
	string LastName;
	string Email;
	string Password;
	[]Task Tasks;
};

vector < User > users;
vector < Task > tasks;

size_t usersArrSize() {
	return sizeof(users) / sizeof(users[0]);
}

void CreateUser(string name, string lastName, string email, string password) {
	struct User* user = NULL;

	regex password_regex("^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$");
	regex email_regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	if (name == "" && lastName == "" && email == "" && password == "") {
		cout << "Dane wprowadzone nieprawidlowo" << endl;
		system("PAUSE");
	}

	if (!regex_match(password, password_regex))
	{
		cout << "Haslo musi zawierac przynajmniej 8 znakow, jedna mala litere oraz cyfre." << endl;
	}

	if (!regex_match(email, email_regex)) 
	{
		cout << "Niewlasciwy adres email." << endl;
	}

	user->Name = name;
	user->LastName = lastName;
	user->Email = email;
	user->Password = password;

	users.push_back(*user);
}

void FindUser(string email, string password)
{
	struct User* user;
	for (int i = 0; i < usersArrSize(); i++)
	{
		if (user->Email != email && user->Password != password)
		{
			cout << "Nieprawidlowe dane. Sprobuj ponownie." << endl;
		}
	}
}

User GetUser(string email, string password)
{
	for (int i = 0; i < usersArrSize(); i++) 
	{
		if (users[i].Email != email && users[i].Password != password)
		{
			cout << "Nieprawidlowe dane. Sproboj ponownie." << endl;
			return;
		}
		return users[i];
		break;
	}
}

void CreateNewTask(string title, string description, string initDate, string expDate)
{
	struct Task* newTask = NULL;
	if (title == "" && description == "" && initDate == "" && expDate == "")
	{
		cout << "Nieprawidlowo wprowadzone dane"
	}
}

void ChangeUserData()
{
	struct User* user;
	int val;
	string name, lastName, email, password;
	cout << "Zmiana danych uzytkownika\n Opcje:" << endl;
	cout << "1 - Zmiana imienia\n 2 - Zmiana nazwiska\n 3 - Zmiana adresu email\n 4 - Zmiana hasla\n" << endl;
	cin >> val;
	switch(val) {
		case 1:
			cout << "Wprowadz nowe imie" << endl;
			cin >> name;
			user->Name = name;
		case 2:
			cout << "Wprowadz nowe nazwisko" << endl;
			cin >> lastName;
			user->LastName = lastName;
		case 3:
			cout << "Wprowadz nowy email" << endl;
			cin >> email;
			user->Email;
		case 4:
			cout << "Wprowadz nowe haslo" << endl;
			cin >> password;
			user->Password = password;
	}

}

int main()
{

}
