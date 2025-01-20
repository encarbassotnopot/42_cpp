#pragma once
#include "Contact.hpp"
#define MAX_CONTACTS 8
class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
	size_t _index;
	size_t _size;

public:
	PhoneBook(/* args */);
	~PhoneBook();
	void mainMenu();
	void newContact();
	void listContacts();
};