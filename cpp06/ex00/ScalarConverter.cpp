#include "ScalarConverter.hpp"
#include <limits>

static bool isCharLit(const std::string &rep)
{
	if (rep.length() != 1)
		return false;
	if (rep[0] > '0' && rep[0] < '9')
		return false;
	return true;
}

static bool isIntLit(const std::string &rep)
{
	size_t i = 0;

	if (rep[i] == '+' || rep[i] == '-')
		i++;
	for (; i < rep.length(); i++)
	{
		if (rep[i] < '0' || rep[i] > '9')
			return false;
	}
	if (rep[i] == '\0')
		return true;

	return false;
}

static bool isDoubleLit(const std::string &rep)
{
	size_t i = 0;

	if (rep == "inf" || rep == "+inf" || rep == "-inf" || rep == "nan")
		return true;
	if (rep[i] == '+' || rep[i] == '-')
		i++;
	for (; i < rep.length(); i++)
	{
		if (rep[i] == '.')
			break;
		if (rep[i] < '0' || rep[i] > '9')
			return false;
	}
	if (rep[i] == '.')
		i++;
	for (; i < rep.length(); i++)
	{
		if (rep[i] < '0' || rep[i] > '9')
			return false;
	}
	if (rep[i] == '\0')
		return true;

	return false;
}

static bool isFloatLit(const std::string &rep)
{
	size_t i = 0;

	if (rep == "inff" || rep == "+inff" || rep == "-inff" || rep == "f")
		return true;
	if (rep[i] == '+' || rep[i] == '-')
		i++;
	for (; i < rep.length(); i++)
	{
		if (rep[i] == '.' || rep[i] == 'f')
			break;
		if (rep[i] < '0' || rep[i] > '9')
			return false;
	}
	if (rep[i] == '.')
		i++;
	for (; i < rep.length(); i++)
	{
		if (rep[i] == 'f')
			break;
		if (rep[i] < '0' || rep[i] > '9')
			return false;
	}
	if (rep[i] != 'f')
		return false;
	i++;
	if (rep[i] == '\0')
		return true;
	return false;
}

static ScalarType getType(const std::string &rep)
{
	if (isCharLit(rep))
		return CHAR;
	if (isIntLit(rep))
		return INT;
	if (isDoubleLit(rep))
		return DOUBLE;
	if (isFloatLit(rep))
		return FLOAT;
	return INVALID;
}

void ScalarConverter::convert(const std::string &representation)
{
	ScalarType ogType = getType(representation);

	if (ogType == CHAR)
	{
		if (isprint(representation[0]))
			std::cout << "char: " << representation[0] << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(representation[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(representation[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(representation[0]) << std::endl;
	}
	if (ogType == INT)
	{
		int val = atoi(representation.c_str());
		if (val > 0 && val < 128 && isprint(static_cast<char>(val)))
			std::cout << "char: " << static_cast<char>(val) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << val << std::endl;
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << std::endl;
	}
	if (ogType == FLOAT)
	{
		float val = atof(representation.c_str());
		if (val > 0 && val < 128 && isprint(static_cast<char>(val)))
			std::cout << "char: " << static_cast<char>(val) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(val) << std::endl;
		std::cout << "float: " << val << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << std::endl;
	}
	if (ogType == DOUBLE)
	{
		double val = atof(representation.c_str());
		if (val > 0 && val < 128 && isprint(static_cast<char>(val)))
			std::cout << "char: " << static_cast<char>(val) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(val) << std::endl;
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << val << std::endl;
	}
	if (ogType == INVALID)
		std::cout << "couldn't assess scalar type from string" << std::endl;
}
