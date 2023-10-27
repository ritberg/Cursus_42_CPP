/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:03:02 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/25 19:03:03 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/*  Heap allocation using dynamic memory allocation
    with 'new' operator. Free with 'delete' in main */
Zombie *newZombie(std::string name)
{
    Zombie *zombie2 = new Zombie(name);
    return (zombie2);
}
