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
    std::cout << "A zombie" << this->getName() << " is born!" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Oh no! The zombie " << this->getName() << " died" << std::endl;
    return;
}

std::string Zombie::getName(void)
{
    return (this->_name);
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

void    Zombie::announce(void)
{
    std::cout << this->getName() << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
