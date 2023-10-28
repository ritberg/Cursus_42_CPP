/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:49:07 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:49:09 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <string>
# include "Weapon.hpp"

class	HumanA {

public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA(void);
    void    attack();

/* without & it didn't work */
private:
    std::string _name;
    Weapon& _weapon;

};

#endif
