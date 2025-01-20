/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:29:23 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 17:00:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string variable: " << &string << std::endl;
	std::cout << "Address of held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of held by stringREF: " << &stringREF << std::endl
			  << std::endl;

	std::cout << "Value of string variable: " << string << std::endl;
	std::cout << "Value pointeed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointeed to by stringREF: " << stringREF << std::endl;
}
