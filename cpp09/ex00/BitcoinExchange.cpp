#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &database)
{
	std::ifstream ifstream(database.c_str());
	if (!ifstream.is_open())
		throw std::ios_base::failure("Couldn't open the Bitcoin Prices database");

	// skip header
	ifstream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (ifstream.good())
	{
		try
		{
			std::string dateStr;
			float val;

			getline(ifstream, dateStr, ',');
			Date date(dateStr);

			ifstream >> val;
			if (val < 0)
				throw std::invalid_argument(dateStr + " => Found negative value in database");

			if (ifstream.fail())
			{
				throw std::invalid_argument("Error parsing line");
				ifstream.clear();
				ifstream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			dbMap.insert(std::pair<Date, float>(date, val));
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error reading from Bitcoin Prices DB: " << e.what() << std::endl;
		}
		ifstream >> std::ws;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;
	this->dbMap = other.dbMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::map<Date, float> &BitcoinExchange::getDb() const { return dbMap; }

// TODO: fer maco això
void BitcoinExchange::evaluateBtcValue(const std::string &database)
{
	std::ifstream ifstream(database.c_str());
	if (!ifstream.is_open())
		throw std::ios_base::failure("Couldn't open values database");

	// skip header
	ifstream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (ifstream.good())
	{
		try
		{
			std::string dateStr;
			float val;

			getline(ifstream, dateStr, '|');
			Date date(dateStr);

			ifstream >> val;
			if (val < 0)
				throw std::invalid_argument(dateStr + " => Found negative value in database");
			if (val > 1000)
				throw std::invalid_argument(dateStr + " => Found value over 1000");

			if (ifstream.fail())
			{
				throw std::invalid_argument("Error parsing line");
				ifstream.clear();
				ifstream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			std::cout << date << "=" << val << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error reading from values DB: " << e.what() << std::endl;
		}
		ifstream >> std::ws;
	}
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &btc)
{
	for (std::map<Date, float>::const_iterator it = btc.getDb().begin(); it != btc.getDb().end(); ++it)
		os << (*it).first << " - " << (*it).second << std::endl;
	return os;
}
