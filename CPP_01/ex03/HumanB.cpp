/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:49:53 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:49:55 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

/*  To be more explicit that there no weapons, we could add a pointer to NULL: 
    `HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)`
*/
HumanB::HumanB(const std::string& name) : _name(name)
{
    std::cout << "The HumanB named " << _name << " has no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "The HumanB " << this->_name << " died" << std::endl;
    return;
}

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with " << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
