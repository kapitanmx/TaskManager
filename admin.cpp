#include "admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string id, string name, string email, string password)
	: ID(id), Name(name), Email(email), Password(password)
{}

void Admin::EditAdmin(string id, string option, string value)
{}

Admin::~Admin() {}