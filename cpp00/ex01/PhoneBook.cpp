#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_size = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::newContact()
{
	Contact c;
	if (c.init())
		return;
	this->_contacts[this->_index] = c;
	this->_index = _index + 1 % 8;
	if (this->_size < 8)
		this->_size++;
}

void PhoneBook::listContacts()
{
	if (this->_size == 0)
	{
		std::cout << "No contacts found" << std::endl;
		return;
	}

	std::cout << "| Index      | First Name | LastName   | Nickname   |" << std::endl;
	for (size_t i = 0; i < this->_size; i++)
	{
		std::cout << "| " << i << "          | " << this->_contacts[i].shortDetails() << std::endl;
	}
	size_t index;
	do
	{
		std::cout << "Enter an index:" << std::endl;
		std::cin >> index;
		if (std::cin.fail() || index >= this->_size)
			std::cout << "Error: Enter a number between 0 and " << this->_size - 1 << std::endl;
		else
			break;
	} while (std::cin.good());
	if (!std::cin.good())
		return;
	std::cout << this->_contacts[index].fullDetails() << std::endl;
}

void PhoneBook::mainMenu()
{
	std::string input;
	do
	{
		std::cout << "Enter an option: (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			this->newContact();
		else if (input == "SEARCH")
			listContacts();
		else if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "Goodbye" << std::endl;
			break;
		}
		else
			std::cout << "Invalid option." << std::endl;
	} while (std::cin.good());
}