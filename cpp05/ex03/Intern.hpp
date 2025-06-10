#pragma once
#include <string>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{

public:
	/** Constructors/desctructors **/
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	/** Functions **/
	AForm *makeForm(const std::string &name, const std::string &target);
};
