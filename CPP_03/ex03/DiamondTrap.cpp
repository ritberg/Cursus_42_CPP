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
    setName("Default");
    ClapTrap::_name = "Default_clap_name";
    setHitPoints(FragTrap::_hitPoints2);
    setEnergyPoints(ScavTrap::_energyPoints1);
    setAttackDamage(FragTrap::_attackDamage2);

    std::cout << GREEN "🟢 From DiamondTrap. Default constructor for " << this->_name<< " called" RESET << std::endl;

    std::cout << "hitPoints[100]: " << this->_hitPoints << std::endl;
	std::cout << "energyPoints[50]: " << this->_energyPoints << std::endl;
	std::cout << "attackDamage[30]: " << this->_attackDamage << std::endl;

    return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"),
                                        ScavTrap(name + "_clap_name")
{
    setName(name + "_clap_name");
    setHitPoints(FragTrap::_hitPoints2);
    setEnergyPoints(ScavTrap::_energyPoints1);
    setAttackDamage(FragTrap::_attackDamage2);

    std::cout << GREEN "🟢 From DiamondTrap. Str constructor for " << name << " called" RESET << std::endl;

    std::cout << "hitPoints[100]: " << this->_hitPoints << std::endl;
	std::cout << "energyPoints[50]: " << this->_energyPoints << std::endl;
	std::cout << "attackDamage[30]: " << this->_attackDamage << std::endl;

    return;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    std::cout << "🟢 From DiamondTrap. Copy constructor for " << src.getName() << " called" << std::endl; // why this->name dsn't work?
    *this = src;
    return;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << GREEN "🟢 From DiamondTrap. Destructor for " << this->_name << " called" RESET << std::endl;
    return;
}

/********    Assignment and outstream perators overloads             ***********/

DiamondTrap&  DiamondTrap::operator=(DiamondTrap const & rhs)
{
    std::cout << "🟢 From DiamondTrap: Copy assignment operator for " << rhs.getName() << " called" << std::endl; // why this->name dsn't work?
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_attackDamage = rhs.getAttackDamage();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, DiamondTrap const & i)
{
    o << i;
    return (o);
}

/************       member functions attack and guardGate        ***********/

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

 void   DiamondTrap::whoAmI(void)
    {
        std::cout << "🟢 From DiamondTrap. My name is " << this->_name << std::endl;
        std::cout << "🟢 From DiamondTrap. My ClapTrap name is " << ClapTrap::_name << std::endl;
        return;
    }

/**********           accessors                ***********/

void    DiamondTrap::setName(std::string name)
{
    this->_name = name;
    return;
}

void    DiamondTrap::setHitPoints(unsigned int amount)
{
    this->_hitPoints = amount;
    return;
}

void    DiamondTrap::setEnergyPoints(unsigned int amount)
{
    this->_energyPoints = amount;
    return;
}

void    DiamondTrap::setAttackDamage(unsigned int amount)
{
    this->_attackDamage = amount;
    return;
}