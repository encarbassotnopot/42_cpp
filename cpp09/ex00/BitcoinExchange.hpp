#include <map>
#include <fstream>
#include "Date.hpp"

class BitcoinExchange
{
private:
	std::map<Date, float> dbMap;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &database);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	const std::map<Date, float> &getDb() const;
	void evaluateBtcValue(const std::string &database);
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &btc);
