/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:22:26 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 13:24:26 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unspecified animal type")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal assignation operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal sounds🐌🐛🐞" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}