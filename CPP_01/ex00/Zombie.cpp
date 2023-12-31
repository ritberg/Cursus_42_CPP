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

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "A zombie named " << this->_name << " is born" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Oh no! The zombie " << this->_name << " died" << std::endl;
    return;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
