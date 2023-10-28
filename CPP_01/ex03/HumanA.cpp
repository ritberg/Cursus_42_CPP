/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:49:23 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:49:25 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    std::cout << "The HumanA named " << _name << " took the " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "The HumanA " << this->_name << " died" << std::endl;
    return;
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with " << _weapon.getType() << std::endl;
}
