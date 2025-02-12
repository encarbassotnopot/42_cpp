/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:26:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 12:35:46 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
class WrongAnimal
{
protected:
	std::string type;
	WrongAnimal(const std::string &type);

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const &other);
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};