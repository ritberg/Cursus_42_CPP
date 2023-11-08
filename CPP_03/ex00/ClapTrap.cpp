/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor for " << name << " called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "Copy constructor for " << this->_name << " called" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor for " << this->_name << " called" << std::endl;
    return;
}

/********    Assignment and outstream perators overloads             ***********/

ClapTrap&  ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_attackDamage = rhs.getAttackDamage();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, ClapTrap const & i)
{
    o << i;
    return (o);
}

/**********           accessors                ***********/

unsigned int ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}

/************       member functions            ***********/

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->takeDamage(this->_attackDamage);
        this->beRepaired(1);
    }
    else
        std::cout << "Too few damage points to attack" << std::endl;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
        << this->_attackDamage << " points of damage!" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " took " << amount << " attack damage points" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_energyPoints++;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points"
        << " and " << this->_hitPoints << " hit points" << std::endl;
    return;
}
