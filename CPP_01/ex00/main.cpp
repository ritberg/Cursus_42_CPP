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
#include <string>
#include <iostream>

int main()
{
    Zombie *zombie1 = newZombie("Foo"); /* Heap allocation */
    zombie1->announce();
    randomChump("Hoho");
   
    delete zombie1;

    return (0);
}
