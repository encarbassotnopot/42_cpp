#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << '\n';
		return 1;
	}

	BitcoinExchange btc;
	try
	{
		btc = BitcoinExchange("./dd");
		std::cout << btc << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	btc.evaluateBtcValue(argv[1]);
}
