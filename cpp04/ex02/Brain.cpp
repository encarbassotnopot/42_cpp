/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 18:25:53 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "some idea";
}

Brain::Brain(Brain const &other)
{
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other.getIdea(i);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	return (_ideas[i]);
}

void Brain::setIdea(int i, const std::string &idea)
{
	_ideas[i] = idea;
}