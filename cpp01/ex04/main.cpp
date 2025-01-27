/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:29:34 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/27 18:11:47 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	Replace replace(argv[1]);
}