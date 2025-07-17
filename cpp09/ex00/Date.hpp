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

	Date(int day, int month, int year);

public:
	Date();
	Date(const std::string &textRep);
	Date &operator=(const Date &other);
	Date(const Date &other);
	~Date();

	bool operator<(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator==(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>=(const Date &other) const;

	int getYear() const;
	int getMonth() const;
	int getDay() const;
};

std::ostream &operator<<(std::ostream &s, const Date &d);
