/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"

unsigned int ScavTrap::_hitPoints1 = 100;
unsigned int ScavTrap::_energyPoints1 = 50;
unsigned int ScavTrap::_attackDamage1 = 20;

/*******     Default constructor, copy constructor, destructor      ***********/

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_name = "Default";
    this->_hitPoints = _hitPoints1;
    this->_energyPoints = _energyPoints1;
    this->_attackDamage = _attackDamage1;

    std::cout << VIOLET "🟣 From ScavTrap. Default constructor for " << this->_name<< " called" RESET << std::endl;
    return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = _hitPoints1;
    this->_energyPoints = _energyPoints1;
    this->_attackDamage = _attackDamage1;
    std::cout << VIOLET "🟣 From ScavTrap. Str constructor for " << name << " called" RESET << std::endl;
    return;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << VIOLET "🟣 From ScavTrap. Copy constructor for " << src.getName() << " called" RESET << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << VIOLET "🟣 From ScavTrap. Destructor for " << this->_name << " called" RESET << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

ScavTrap&  ScavTrap::operator=(ScavTrap const & rhs)
{
    std::cout << VIOLET "🟣 From ScavTrap. Copy assignment operator for " << rhs.getName() << " called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_attackDamage = rhs.getAttackDamage();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
    }
    return (*this);
}

/************       member functions attack and guardGate        ***********/

void ScavTrap::attack(const std::string& target)
{
    if (target == this->_name)
    {
        std::cout << VIOLET "🟣 From ScavTrap. ClapTrap " << this->_name << " attacks itself! Impossible action" RESET << std::endl;
        return;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << VIOLET "🟣 From ScavTrap. ClapTrap " << this->_name << " has too few hit points to attack" RESET << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0)
    {
        std::cout << VIOLET "🟣 From ScavTrap. ClapTrap " << this->_name << " has too few energy points to attack" RESET << std::endl;
        return;
    }
    std::cout << VIOLET "🟣 From ScavTrap. ClapTrap " << this->_name << " attacks " << target << ", causing "
            << this->_attackDamage << " points of damage!" RESET << std::endl;
    // this->_hitPoints -= this->_attackDamage;
    this->_energyPoints--;
    return;
}

void ScavTrap::guardGate(void)
{
    std::cout << VIOLET "🟣 From ScavTrap. ScavTrap " << this->_name << " has entered in Gate keeper mode" RESET << std::endl;
    return;
}
