/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:38:07 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/12 13:27:40 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	/*
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); // will NOT output the cat sound!
	wrongMeta->makeSound();
	delete k; // this will segfault
	delete wrongMeta;
	*/
	return 0;
}