/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "FragTrap.hpp"

unsigned int FragTrap::_hitPoints2 = 100;
unsigned int FragTrap::_energyPoints2 = 100;
unsigned int FragTrap::_attackDamage2 = 30;

/*******     Default constructor, copy constructor, destructor      ***********/

FragTrap::FragTrap(void) : ClapTrap()
{
    this->_name = "Default";
    this->_hitPoints = _hitPoints2;
    this->_energyPoints = _energyPoints2;
    this->_attackDamage = _attackDamage2;
    std::cout << YELLOW "🟡 From FragTrap. Default constructor for " << this->_name<< " called" RESET << std::endl;
    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = _hitPoints2;
    this->_energyPoints = _energyPoints2;
    this->_attackDamage = _attackDamage2;
    std::cout << YELLOW "🟡 From FragTrap. Str constructor for " << name << " called" RESET << std::endl;
    return;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << YELLOW "🟡 From FragTrap. Copy constructor for " << src.getName() << " called" RESET << std::endl;
    *this = src;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << YELLOW "🟡 From FragTrap. Destructor for " << this->_name << " called" RESET << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

FragTrap&  FragTrap::operator=(FragTrap const & rhs)
{
    std::cout << YELLOW "🟡 From FragTrap. Copy assignment operator for " << rhs.getName() << " called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_attackDamage = rhs.getAttackDamage();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
    }
    return (*this);
}

/************       member function highFivesGuys        ***********/

void    FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
    {
        std::cout << YELLOW "🟡 From FragTrap: " << this->_name << " is dead, can't ask for a high fives ✋ " RESET << std::endl;
        return;
    }
    std::cout << YELLOW "🟡 From FragTrap: is asking for a high fives ✋ " RESET << std::endl;
    return;
}
