#include "AForm.hpp"
#include <iostream>

// Constructors/destructors
AForm::AForm() : _name("Default Form"), _signGrade(50), _execGrade(50), _isSigned(false) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other.getName()),
								   _signGrade(other.getSignGrade()),
								   _execGrade(other.getSignGrade()),
								   _isSigned(other.isSigned()) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other.isSigned();
	}
	return *this;
}

AForm::~AForm() {}

// Getters
const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

// Functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	std::cout << bureaucrat.getName() << " is signing " << this->getName() << std::endl;

	if (bureaucrat.getGrade() <= _signGrade)
	{
		_isSigned = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }
const char *AForm::NotSignedException::what() const throw() { return "Form not signed"; }

std::ostream &operator<<(std::ostream &ostream, const AForm &f)
{
	ostream << "Form name: " << f.getName() << ", Form sign grade: " << f.getSignGrade() << ", Form exec grade: " << f.getExecGrade();
	if (f.isSigned())
		ostream << ", Form signed";
	else
		ostream << ", Form NOT signed";
	return ostream;
}
