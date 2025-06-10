#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Intern intern;

	AForm *form1 = intern.makeForm("shrubbery creation", "Shrubbery");
	AForm *form2 = intern.makeForm("robotomy request", "Robot");
	AForm *form3 = intern.makeForm("presidential pardon", "Jim");
	delete form1;
	delete form2;
	delete form3;

	AForm *wrongForm = intern.makeForm("doesn't exist", "nobody");
	delete wrongForm;
}
