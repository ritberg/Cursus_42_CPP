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
    int N;
    std::string horde_name;

    std::cout << "Choose a number of zombies: ";
    std::cin >> N;

    std::cout << "Choose a name of the horde: ";
    std::cin >> horde_name;

    Zombie *zombie1 = zombieHorde(N, horde_name);
   
    delete [] zombie1;

    return (0);
}
