/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# define RESET	"\e[0m"
# define VIOLET	"\033[35m"

class ScavTrap : virtual public ClapTrap {
 
    public:
        ScavTrap(void);
        ScavTrap(std::string _name);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap(void);

        ScavTrap&  operator=(ScavTrap const & rhs);

        void attack(const std::string& target);

        void guardGate(void);

    protected:
        static unsigned int _hitPoints1;
        static unsigned int _energyPoints1;
        static unsigned int _attackDamage1;


};

#endif