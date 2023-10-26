/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:02:29 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/25 19:02:30 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie  zombie = Zombie("Foo");
    Zombie* newZombie = zombie.newZombie("Foo");
    newZombie->randomChump("Foo");
   
    delete newZombie;

    return (0);
}
