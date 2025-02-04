/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:09:20 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/04 20:04:32 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Replacer
{
private:
	std::string _og_filename;
	std::string _new_filename;

public:
	Replacer(std::string og_filename);
	~Replacer();
	void do_replace(std::string og_text, std::string new_text);
};
