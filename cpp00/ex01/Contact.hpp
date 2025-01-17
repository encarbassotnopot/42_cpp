#pragma once

#include <string>
#include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNum;
	std::string _secret;
	std::string _getInput(std::string msg);
	std::string _getShort(std::string info);

public:
	Contact();
	~Contact();
	int init();
	std::string shortDetails();
	std::string fullDetails();
};