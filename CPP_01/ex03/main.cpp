/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:47:53 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:48:17 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*  
Scenario 1 (HumanA):
- we need a direct association with a `Weapon` object 
- `bob` is designed to always work with a specific weapon
	and cannot be without one.

Scenario 2 (HumanB):
- we have flexibility in managing the association with a `Weapon` object
- `jim` can work with weapons and without (if we set the pointer to NULL).
	References cannot be set to ptr NULL!!
*/
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
