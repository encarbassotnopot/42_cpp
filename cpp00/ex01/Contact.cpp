#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

/**
 * Asks for user input, returns a string made up of 10 chars.
 */
std::string Contact::_getInput(std::string msg)
{
	std::string input;
	do
	{
		std::cout << msg << std::endl;
		std::getline(std::cin, input);
	} while (!input.size() && std::cin);
	return input;
}
/**
 * Returns -1 on input error. 0 otherwise.
 */
int Contact::init()
{
	this->_firstName = _getInput("Enter the contact's first name:");
	if (!std::cin.good())
		return -1;
	this->_lastName = _getInput("Enter the contact's last name:");
	if (!std::cin.good())
		return -1;
	this->_nickname = _getInput("Enter the contact's nickname:");
	if (!std::cin.good())
		return -1;
	this->_phoneNum = _getInput("Enter the contact's phone number:");
	if (!std::cin.good())
		return -1;
	this->_secret = _getInput("Enter the contact's darkest secret:");
	if (!std::cin.good())
		return -1;
	return 0;
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
	return this->_getShort(_firstName) + " | " + this->_getShort(_lastName) + " | " + this->_getShort(_nickname) + " |";
}

std::string Contact::fullDetails()
{
	return "First name: " + this->_firstName +
		   "\nLast name: " + this->_lastName +
		   "\nNickname: " + this->_nickname +
		   "\nPhone Number: " + this->_phoneNum +
		   "\nDarkest Secret: " + this->_secret;
}
