/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:09:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/02/04 20:05:13 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string og_filename) : _og_filename(og_filename), _new_filename(og_filename + ".replace") {}

Replacer::~Replacer() {}

std::string my_replace(std::string line, std::string og_text, std::string new_text)
{
	size_t pos;
	while ((pos = line.find(og_text)) != std::string::npos)
		line = line.substr(0, pos) + new_text + line.substr(pos + og_text.length());
	return line;
}

void Replacer::do_replace(std::string og_text, std::string new_text)
{
	std::fstream og_file(_og_filename.c_str(), std::ios::in);
	if (!og_file.is_open())
	{
		std::cerr << "Error: Could not open file " << _og_filename << std::endl;
		return;
	}
	std::fstream new_file(_new_filename.c_str(), std::ios::out | std::ios::trunc);
	if (!new_file.is_open())
	{
		std::cerr << "Error: Could not open file " << _new_filename << std::endl;
		return;
	}
	std::string line;
	do
	{
		std::getline(og_file, line);
		while (line.find(og_text) != std::string::npos)
			line = my_replace(line, og_text, new_text);
		new_file << line << std::endl;
	} while (!og_file.eof());
}