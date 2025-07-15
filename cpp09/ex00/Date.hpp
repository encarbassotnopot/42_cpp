#pragma once
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

	Date();
	Date &operator=(const Date &other);
	Date(const Date &other);

public:
	Date(int day, int month, int year);
	Date(const std::string &textRep);
	~Date();

	bool operator<(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator==(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>=(const Date &other) const;

	const std::string &getDate() const;
};
