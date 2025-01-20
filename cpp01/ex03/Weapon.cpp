/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:03:34 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 18:50:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {};

Weapon::~Weapon()
{
	std::clog << "Weapon " << _type << " destroyed" << std::endl;
};

void Weapon::setType(std::string type) { _type = type; };

std::string Weapon::getType() { return _type; };