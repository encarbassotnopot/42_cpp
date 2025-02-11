/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:15:19 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/11 11:26:39 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
int main()
{
	FragTrap frag("fragtrap");

	for (int i = 0; i < 5; i++)
	{
		frag.attack("enemy");
		frag.takeDamage(1);
	}
	frag.beRepaired(5);
	frag.highFivesGuys();
}