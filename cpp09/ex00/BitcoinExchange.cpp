#include "BitcoinExchange.hpp"
#include <map>
#include "Date.hpp"

class BitcoinExchange
{
private:
    std::map<Date, float> m;

public:
    BitcoinExchange(/* args */);
    ~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}
