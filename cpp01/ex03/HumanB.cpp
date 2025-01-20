/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:09:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 18:53:39 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
};

HumanB::~HumanB() {};

void HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their empty hand" << std::endl;
};

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
};