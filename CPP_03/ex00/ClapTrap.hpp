/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap {
 
    public:
        ClapTrap(void);
        ClapTrap(std::string _name);
        ClapTrap(ClapTrap const & src);
        ~ClapTrap(void);

        ClapTrap&  operator=(ClapTrap const & rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string     getName(void) const;
        unsigned int    getHitPoints() const;
        unsigned int    getEnergyPoints() const;
        unsigned int    getAttackDamage() const;

    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

};

std::ostream&   operator<<(std::ostream& o, ClapTrap const & i);

#endif