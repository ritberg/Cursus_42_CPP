/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:22:24 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 11:22:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombie2 = new Zombie[N];
    {
        for (int i = 0; i < N; ++i)
        {
            zombie2[i].setName(name);
            zombie2[i].announce();
        }
    }
    return (zombie2);
}
