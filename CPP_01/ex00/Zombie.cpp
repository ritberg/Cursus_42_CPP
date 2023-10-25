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
#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Constructor" << name << "called" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Destructor" << name << "called" << std::endl;
    return;
}

std::string Zombie::getName(void)
{
    return (Zombie::name);
}

void    Zombie::announce(void)
{
    std::string name;
    std::cin >> name;
    std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
