/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:26:53 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 10:10:32 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
	_size = 0;
	std::clog << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::clog << "PhoneBook destroyed" << std::endl;
}

void PhoneBook::newContact()
{
	_contacts[_index].init();
	_index = (_index + 1) % MAX_CONTACTS;
	if (_size < MAX_CONTACTS)
		_size++;
}

void PhoneBook::listContacts()
{
	if (_size == 0)
	{
		std::cout << "No contacts found" << std::endl;
		return;
	}

	std::cout << "| Index      | First Name | LastName   | Nickname   |" << std::endl;
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << "| " << i << "          | " << _contacts[i].shortDetails() << std::endl;
	}
	size_t index;
	while (std::cin.good())
	{
		std::cout << "Enter an index:" << std::endl;
		std::cin >> index;
		if (std::cin.fail() || index >= _size)
		{
			if (std::cin.eof())
				return;
			std::cout << "Invalid index." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else
			break;
	}

	std::cout << _contacts[index].fullDetails() << std::endl;
	std::cin.ignore(256, '\n');
}

void PhoneBook::mainMenu()
{
	std::string input;
	while (std::cin)
	{
		std::cout << "Enter an option: (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			newContact();
		else if (input == "SEARCH")
			listContacts();
		else if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "Goodbye" << std::endl;
			break;
		}
		else
			std::cout << "Invalid option." << std::endl;
	}
}