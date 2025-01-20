/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:26:32 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 16:26:41 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];

		for (size_t j = 0; j < str.size(); j++)
		{
			std::cout << (char)toupper(str[j]);
		}
	}
	std::cout << std::endl;
}