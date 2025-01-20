/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:11:36 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/01/20 18:39:42 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon();
	void setType(std::string type);
	std::string getType();
};