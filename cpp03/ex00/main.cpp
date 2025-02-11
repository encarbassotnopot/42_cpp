/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:15:19 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/10 18:17:15 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main()
{
	ClapTrap claptrap("trapclap");

	for (int i = 0; i < 5; i++)
	{
		claptrap.attack("enemy");
		claptrap.takeDamage(1);
	}
	claptrap.beRepaired(5);
	for (int i = 0; i < 5; i++)
	{
		claptrap.attack("enemy");
		claptrap.takeDamage(1);
	}
	claptrap.beRepaired(5);
}