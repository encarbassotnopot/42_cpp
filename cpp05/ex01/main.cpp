#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat bHigh("high", 2);
	Bureaucrat bLow("low", 150);
	Form fLow("low", 140, 140);
	Form fHigh("low", 1, 1);

	bHigh.signForm(fLow);
	bHigh.signForm(fHigh);
	bLow.signForm(fLow);
	bLow.signForm(fHigh);
}
