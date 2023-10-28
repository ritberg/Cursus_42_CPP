/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:49:41 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:49:43 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <string>
# include "Weapon.hpp"

class	HumanB {

public:
    HumanB(const std::string& name);
    ~HumanB(void);
    void    attack();
    void    setWeapon(Weapon &weapon);

/* without & it didn't work */
private:
    std::string _name;
    Weapon* _weapon;

};

#endif
