#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " is executing " << this->getName() << std::endl;

	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}

	std::cout << "* drilling noises *" << std::endl;

	// we use the default seed of 1
	if (std::rand() > RAND_MAX / 2)
		std::cout << "Robotomy on " << _target << " has succeded" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " has failed" << std::endl;
}