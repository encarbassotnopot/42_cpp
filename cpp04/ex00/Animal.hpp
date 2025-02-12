/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:26:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 12:35:46 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
class Animal
{
protected:
	std::string type;
	Animal(const std::string &type);

public:
	Animal();
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};