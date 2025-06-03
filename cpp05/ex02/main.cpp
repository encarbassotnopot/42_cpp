#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat alice("Alice", 2);
	Bureaucrat bob("Bob", 130);
	ShrubberyCreationForm form1("Shrubbery");
	RobotomyRequestForm form2("Robot");
	PresidentialPardonForm form3("James");

	std::cout << alice << std::endl;
	std::cout << form1 << std::endl;
	form1.beSigned(alice);
	std::cout << form1 << std::endl;
	form1.execute(alice);

	std::cout << bob << std::endl;
	try
	{
		form2.beSigned(bob);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		form2.execute(alice);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	form2.beSigned(alice);
	form2.execute(alice);
	form2.execute(alice);
	form2.execute(alice);
	form3.beSigned(alice);
	form3.execute(alice);
}
