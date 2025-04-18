#pragma once
#include <string>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	/** Constructors/desctructors **/
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	/** Getters **/
	const std::string &getName() const;
	int getGrade() const;

	/** Operators **/
	void operator++(int);
	void operator--(int);

	/** Exceptions **/
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Grade too high!"; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Grade too low!"; }
	};
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &b);
