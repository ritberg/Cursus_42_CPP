/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define RESET	"\e[0m"
# define GREEN "\033[32m"

class DiamondTrap : public ScavTrap, public FragTrap {
 
    public:
        DiamondTrap(void);
        DiamondTrap(std::string _name);
        DiamondTrap(DiamondTrap const & src);
        ~DiamondTrap(void);

        DiamondTrap&  operator=(DiamondTrap const & rhs);

        void attack(const std::string& target);

        void whoAmI(void);

        void    setName(std::string name);
        void    setHitPoints(unsigned int amount);
        void    setEnergyPoints(unsigned int amount);
        void    setAttackDamage(unsigned int amount);

    private:
        std::string _name;

};

std::ostream&   operator<<(std::ostream& o, DiamondTrap const & i);

#endif