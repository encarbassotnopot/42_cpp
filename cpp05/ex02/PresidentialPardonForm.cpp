#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " is executing " << this->getName() << std::endl;

	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}