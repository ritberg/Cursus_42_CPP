/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:48:38 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:48:39 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
   // std::cout << "weapon constructor: " << this->_type << std::endl;
    return;
}

Weapon::~Weapon(void)
{
  //  std::cout << "weapon destructor" << std::endl;
    return;
}

std::string const&  Weapon::getType(void) const
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}
