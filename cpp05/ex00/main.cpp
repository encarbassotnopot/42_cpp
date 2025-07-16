#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat invalid("errorr", 200);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat high("high", 2);
	std::cout << high << ". Incrementing" << std::endl;
	try
	{
		high++;
		std::cout << high << ". Incrementing" << std::endl;
		high++;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat low("low", 150);
	std::cout << low << ". Decrementing" << std::endl;
	try
	{
		low--;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
