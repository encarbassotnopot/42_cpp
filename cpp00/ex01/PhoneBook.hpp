/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:26:55 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 16:27:00 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"
#define MAX_CONTACTS 8
class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
	size_t _index;
	size_t _size;

public:
	PhoneBook();
	~PhoneBook();
	void mainMenu();
	void newContact();
	void listContacts();
};