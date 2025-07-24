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

float BitcoinExchange::getBtcValueAt(const Date &d)
{
	std::map<Date, float>::iterator low = this->dbMap.lower_bound(d);
	if (low == this->dbMap.end())
		throw std::out_of_range("Values for date not found in DB");
	return low->second;
}

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
			float valAtDate;

			getline(ifstream, dateStr, '|');
			Date date(dateStr);

			ifstream >> val;
			if (val < 0)
				throw std::invalid_argument(dateStr + " => Found negative value in database");
			if (val > 1000)
				throw std::invalid_argument(dateStr + " => Found value over 1000");

			if (ifstream.fail())
			{
				ifstream.clear();
				ifstream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::invalid_argument("Error parsing line");
			}

			valAtDate = getBtcValueAt(date);

			std::cout << date << "=>" << val << " = " << val * valAtDate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error reading from values input: " << e.what() << std::endl;
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
