#include <iostream>
#include "BitcoinExchange.hpp"

int main()
{
	try
	{
		BitcoinExchange btc("./dd");
		std::cout << btc << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
