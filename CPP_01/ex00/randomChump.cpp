/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:03:15 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/25 19:03:16 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  Stack allocation. When the function randomChump ends,
    the object zombie2 is automatically destroyed */
void randomChump(std::string name)
{
    Zombie  zombie2 = Zombie(name);
    zombie2.announce();
    return;
}
