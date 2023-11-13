/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"

# define RESET	"\e[0m"
# define YELLOW "\033[33m"

class FragTrap : public ClapTrap {
 
    public:
        FragTrap(void);
        FragTrap(std::string _name);
        FragTrap(FragTrap const & src);
        ~FragTrap(void);

        FragTrap&  operator=(FragTrap const & rhs);

        void highFivesGuys(void);

        void    setName(std::string name);
        void    setHitPoints(unsigned int amount);
        void    setEnergyPoints(unsigned int amount);
        void    setAttackDamage(unsigned int amount);


};

std::ostream&   operator<<(std::ostream& o, FragTrap const & i);

#endif