/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:26:43 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 16:26:44 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNum;
	std::string _secret;
	std::string _getInput(std::string msg);
	std::string _getShort(std::string info);

public:
	Contact();
	~Contact();
	void init();
	std::string shortDetails();
	std::string fullDetails();
};