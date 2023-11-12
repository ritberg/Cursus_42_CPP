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

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor for " << this->_name<< " called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Str constructor for " << name << " called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "Copy constructor for " << src.getName() << " called" << std::endl; // why this->name dsn't work?
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor for " << this->_name << " called" << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

ClapTrap&  ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "Copy assignment operator for " << rhs.getName() << " called" << std::endl; // why this->name dsn't work?
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_attackDamage = rhs.getAttackDamage();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, ClapTrap const & i)
{
    o << i;
    return (o);
}

/**********           accessors                ***********/

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

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
    if (target == this->_name)
    {
        std::cout << "ClapTrap " << this->_name << " attacks itself! Impossible action" << std::endl;
        return;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has too few hit points to attack" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has too few energy points to attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
            << this->_attackDamage << " points of damage!" << std::endl;
    // this->_hitPoints -= this->_attackDamage;
    this->_energyPoints--;
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot take damage: there are no hit points left" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot take damage: there are no energy points left" << std::endl;
        return;
    }
    else if (int(this->_hitPoints) - int(amount) < 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot take damage: hit points cannot become negative" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " was attacked and took " << amount << " points of damage";
    std::cout << " (lost " << amount << " hit points)" << std::endl;
    this->_hitPoints -= amount;
    std::cout << "Now ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points left" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired: there are no hit points left" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired: there are no energy points left" << std::endl;
        return;
    }
    else if (this->_hitPoints + amount > 10)
    {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired: it will have more than 10 points" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " repairs itself and gains " << amount
        << " energy points" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints--;
    return;
}
