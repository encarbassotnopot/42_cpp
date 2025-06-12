#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

enum ScalarType
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	static void convert(const std::string &representation);
};
