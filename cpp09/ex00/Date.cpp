#include "Date.hpp"

Date::Date() {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
	{
		throw std::invalid_argument("Invalid date");
	}
}

Date::Date(const std::string &textRep)
{
	int mDay, mMonth, mYear;
	try
	{
		std::stringstream ss(textRep);
		ss >> mYear;
		ss.ignore(1, '-');
		ss >> mMonth;
		ss.ignore(1, '-');
		ss >> mDay;
		*this = Date(mDay, mMonth, mYear);
	}
	catch (const std::exception &e)
	{
		throw std::invalid_argument("Invalid date: " + textRep);
	}
}

Date::Date(const Date &other) { *this = other; }

Date &Date::operator=(const Date &other)
{
	if (*this == other)
		return *this;
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;
}

Date::~Date()
{
}

bool Date::operator<(const Date &other) const
{
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	return day < other.day;
}

bool Date::operator>(const Date &other) const { return other < *this; }

bool Date::operator==(const Date &other) const { return year == other.year && month == other.month && day == other.day; }

bool Date::operator<=(const Date &other) const { return !(*this > other); }

bool Date::operator>=(const Date &other) const { return !(*this < other); }

int Date::getYear() const { return year; }

int Date::getMonth() const { return month; }

int Date::getDay() const { return day; }

std::ostream &operator<<(std::ostream &os, const Date &d)
{
	os << d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
	return os;
}
