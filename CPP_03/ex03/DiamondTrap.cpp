/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "Default";
    ClapTrap::_name = "Default_clap_name";

    this->_hitPoints = FragTrap::_hitPoints2;
    this->_energyPoints = ScavTrap::_energyPoints1;
    this->_attackDamage = FragTrap::_attackDamage2;

    std::cout << GREEN "🟢 From DiamondTrap. Default constructor for " << this->_name<< " called" RESET << std::endl;

    std::cout << GREEN "hitPoints[100]: " RESET << this->_hitPoints << std::endl;
	std::cout << GREEN "energyPoints[50]: " RESET << this->_energyPoints << std::endl;
	std::cout << GREEN "attackDamage[30]: " RESET << this->_attackDamage << std::endl;

    return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"),
                                    FragTrap(name + "_clap_name")
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints2;
    this->_energyPoints = ScavTrap::_energyPoints1;
    this->_attackDamage = FragTrap::_attackDamage2;

    std::cout << GREEN "🟢 From DiamondTrap. Str constructor for " << name << " called" RESET << std::endl;

    std::cout << GREEN "hitPoints[100]: " RESET << this->_hitPoints << std::endl;
	std::cout << GREEN "energyPoints[50]: " RESET << this->_energyPoints << std::endl;
	std::cout << GREEN "attackDamage[30]: " RESET << this->_attackDamage << std::endl;

    return;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    std::cout << GREEN "🟢 From DiamondTrap. Copy constructor for " << src.getName() << " called" RESET << std::endl;
    *this = src;
    return;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << GREEN "🟢 From DiamondTrap. Destructor for " << this->_name << " called" RESET << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

DiamondTrap&  DiamondTrap::operator=(DiamondTrap const & rhs)
{
    std::cout << GREEN "🟢 From DiamondTrap: Copy assignment operator for " << rhs.getName() << " called" RESET << std::endl;
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

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

 void   DiamondTrap::whoAmI(void)
{
        std::cout << GREEN "🟢 From DiamondTrap. My name is " << this->_name << RESET << std::endl;
        std::cout << GREEN "🟢 From DiamondTrap. My ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
        return;
}
