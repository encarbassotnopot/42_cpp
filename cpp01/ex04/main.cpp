/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:29:34 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/04 20:09:34 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	Replacer replacer(argv[1]);
	replacer.do_replace(argv[2], argv[3]);
}