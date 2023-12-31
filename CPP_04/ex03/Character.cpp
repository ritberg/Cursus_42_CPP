/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = 0;
    return;
}

Character::Character(std::string const & name) : _name(name)
{
    std::cout << "Character str constructor for " << name << " called" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = 0;
    return;
}
/*
_inventory() calls:
 for (int i = 0; i < 4; ++i)
    this->_inventory[i] = 0;
*/
Character::Character(Character const & src) : _inventory()
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = src;
    return;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        if (this->_inventory[i])
            delete this->_inventory[i];
    return;
}

Character & Character::operator=(Character const & rhs)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; ++i)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (rhs._inventory[i])
                this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = materia;
            return;
        }
    }
    return;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->_inventory[idx] = 0;
    else
        std::cout << "Index out of range" << std::endl;
    return;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << "Index out of range" << std::endl;
    return;
}
