/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:29:23 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 16:48:12 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main()
{
	int count = 5;
	Zombie *zombies = zombieHorde(count, "hordeMember");
	for (int i = 0; i < count; i++)
		zombies[i].announce();

	delete[] zombies;
}
