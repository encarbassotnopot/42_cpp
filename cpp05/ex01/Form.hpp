#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;

public:
	/** Constructors/desctructors **/
	Form();
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	/** Getters **/
	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	/** Functions **/
	void beSigned(const Bureaucrat &bureaucrat);

	/** Exceptions **/
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &ostream, const Form &f);
