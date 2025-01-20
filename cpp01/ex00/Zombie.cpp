/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:29:15 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 16:29:28 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {};
Zombie::~Zombie()
{
	std::clog << _name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::clog << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}