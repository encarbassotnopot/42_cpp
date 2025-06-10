#include "Intern.hpp"
#include <iostream>

// Constructors/destructors
Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}
static AForm *createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
static AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{

	std::string names[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"};
	AForm *(*forms[])(const std::string &) = {
		createRobotomy,
		createPresidential,
		createShrubbery};

	for (int i = 0; i <= 2; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i](target);
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return NULL;
}
