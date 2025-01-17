#pragma once
#include "Contact.hpp"
class PhoneBook
{
private:
	Contact _contacts[8];
	size_t _index;
	size_t _size;

public:
	PhoneBook(/* args */);
	~PhoneBook();
	void mainMenu();
	void newContact();
	void listContacts();
};