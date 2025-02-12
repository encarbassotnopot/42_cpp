/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:38:07 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 18:27:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal *animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "Animal 1's type " << animals[1]->getType() << std::endl;
	std::cout << "Animal 1's sound ";
	animals[1]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}

	return 0;
}