/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:02:49 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/25 19:02:51 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"


Zombie::Zombie(void)
{
    std::cout << "Give a name to the zombie: ";
    std::cin >> name;
    std::cout << "Constructor " << this->getName() << " called" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Destructor " << this->getName() << " called" << std::endl;
    return;
}

std::string Zombie::getName(void) const
{
    return (this->name);
}

void    Zombie::announce(void)
{
    std::cout << this->getName() << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
