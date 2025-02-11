/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:15:19 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/11 10:45:13 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
int main()
{
	ScavTrap scav("scavtrap");

	for (int i = 0; i < 5; i++)
	{
		scav.attack("enemy");
		scav.takeDamage(1);
	}
	scav.beRepaired(5);
	scav.guardGate();
}