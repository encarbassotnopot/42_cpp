/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:19:55 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/09 12:13:47 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>
class Fixed
{
private:
	int _rawBits;
	static const int _bits = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int number);
	Fixed(const float number);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed);