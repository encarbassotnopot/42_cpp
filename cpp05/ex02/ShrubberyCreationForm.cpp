#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " is executing " << this->getName() << std::endl;

	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}

	std::ofstream file((_target + "_shrubbery").c_str());
	file << "\\ | /" << std::endl;
	file << " \\|/" << std::endl;
	file << "  |" << std::endl;
	file << "  |" << std::endl;
	file << "  |" << std::endl;
	file << "̣-----";
	file.close();
}