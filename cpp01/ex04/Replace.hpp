/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:09:20 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/27 18:11:22 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Replace
{
private:
	std::string _og_filename;
	std::string _new_filename;

public:
	Replace(std::string og_filename);
	~Replace();
	Replace(std::string og_text, std::string new_text);
};
