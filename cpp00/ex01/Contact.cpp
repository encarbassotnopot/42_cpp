#include "Contact.hpp"
#include <limits>

Contact::Contact()
{
	std::clog << "Contact created" << std::endl;
}
Contact::~Contact()
{
	std::clog << "Contact destroyed" << std::endl;
}

/**
 * Asks for user input, returns a string made up of 10 chars.
 */
std::string Contact::_getInput(std::string msg)
{
	std::string input;
	while (!input.size() && std::cin)
	{
		std::cout << msg << std::endl;
		std::getline(std::cin, input);
	};
	return input;
}

/**
 * Asks for a contact's info.
 */
void Contact::init()
{
	_firstName = _getInput("Enter the contact's first name:");
	_lastName = _getInput("Enter the contact's last name:");
	_nickname = _getInput("Enter the contact's nickname:");
	_phoneNum = _getInput("Enter the contact's phone number:");
	_secret = _getInput("Enter the contact's darkest secret:");
}

std::string Contact::_getShort(std::string info)
{
	std::string fill = "          ";
	if (info.length() > 10)
		return info.substr(0, 9) + ".";
	else
		return (info + fill).substr(0, 10);
}

std::string Contact::shortDetails()
{
	return _getShort(_firstName) + " | " + _getShort(_lastName) + " | " + _getShort(_nickname) + " |";
}

std::string Contact::fullDetails()
{
	return "First name: " + _firstName +
		   "\nLast name: " + _lastName +
		   "\nNickname: " + _nickname +
		   "\nPhone Number: " + _phoneNum +
		   "\nDarkest Secret: " + _secret;
}
