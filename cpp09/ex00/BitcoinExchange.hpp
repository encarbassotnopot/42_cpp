#include <map>
#include <fstream>
#include "Date.hpp"

class BitcoinExchange
{
private:
	std::map<Date, float> dbMap;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

public:
	const std::map<Date, float> &getDb() const;
	BitcoinExchange(const std::string &database);
	~BitcoinExchange();
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &btc);
