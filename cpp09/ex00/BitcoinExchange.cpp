#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange(const std::string &database)
{
	std::ifstream ifstream(database.c_str());
	if (!ifstream.is_open())
		throw std::ios_base::failure("Couldn't open the database");

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
			std::cerr << "Error reading from DB: " << e.what() << std::endl;
		}
		ifstream >> std::ws;
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

const std::map<Date, float> &BitcoinExchange::getDb() const { return dbMap; }

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &btc)
{
	for (std::map<Date, float>::const_iterator it = btc.getDb().begin(); it != btc.getDb().end(); ++it)
		os << (*it).first << " - " << (*it).second << std::endl;
	return os;
}
