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
    std::cout << "🟡 From FragTrap. Copy constructor for " << src.getName() << " called" << std::endl; // why this->name dsn't work?
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
    std::cout << "🟡 Copy assignment operator for " << rhs.getName() << " called" << std::endl; // why this->name dsn't work?
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_attackDamage2 = rhs.getAttackDamage();
        this->_hitPoints2 = rhs.getHitPoints();
        this->_energyPoints2 = rhs.getEnergyPoints();
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, FragTrap const & i)
{
    o << i;
    return (o);
}

/************       member function highFivesGuys        ***********/

void    FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
    {
        std::cout << "🟡 FragTrap: " << this->_name << " is dead, can't ask for a high fives ✋ " << std::endl;
        return;
    }
    std::cout << "🟡 FragTrap: is asking for a high fives ✋ " << std::endl;
    return;
}
