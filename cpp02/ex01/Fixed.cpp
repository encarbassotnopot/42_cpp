/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:20:22 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/09 11:03:31 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		_rawBits = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

Fixed::Fixed(int number) : _rawBits(number << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float number) : _rawBits(roundf(number * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	std::cout << "toInt member function called" << std::endl;
	return _rawBits >> _bits;
}

float Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
	return (float)_rawBits / (1 << _bits);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
	ostream << fixed.toFloat();
	return ostream;
}