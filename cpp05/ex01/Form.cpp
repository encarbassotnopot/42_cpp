#include "Form.hpp"
#include <iostream>

// Constructors/destructors
Form::Form() : _name("Default Form"), _signGrade(50), _execGrade(50), _isSigned(false) {}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other.getName()),
								_signGrade(other.getSignGrade()),
								_execGrade(other.getSignGrade()),
								_isSigned(other.isSigned()) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other.isSigned();
	}
	return *this;
}

Form::~Form() {}

// Getters
const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

// Functions
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
	{
		_isSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream &operator<<(std::ostream &ostream, const Form &f)
{
	ostream << "Form name: " << f.getName() << "Form sign grade: " << f.getSignGrade() << "Form exec grade: " << f.getExecGrade();
	if (f.isSigned())
		ostream << "Form signed";
	else
		ostream << "Form NOT signed";
	return ostream;
}
