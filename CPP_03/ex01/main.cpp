/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

/*
    std::string p1 = "Trak";
    std::string p2 = "Tran";

    ClapTrap player0;
    ClapTrap player1(p1);
    ClapTrap player2(p2);

    player1.attack(p2);
    
    ClapTrap claptrap("Player");
    claptrap.attack("Enemy1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("Enemy2");

    // Creating an instance of ScavTrap
    std::cout << std::endl;
    ScavTrap scav("ScavTrapInstance");

    // Testing ScavTrap member functions
    scav.attack("Target 2");
    scav.takeDamage(15);
    scav.beRepaired(5);
*/


	std::string Name0 = "000";
	std::string Name1 = "111";

	ScavTrap	scavTrap(Name0);
	ClapTrap	clapTrap(Name1);

	std::cout << "--------------------------" << std::endl << std::endl;

	clapTrap.attack(Name0); // ClapTrap attack message (from ClapTrap.cpp)
	scavTrap.takeDamage(0); // ClapTrap damage message (from ClapTrap.cpp)
	scavTrap.attack(Name1); // ScavTrap attack message (from ScavTrap.cpp)
	clapTrap.takeDamage(20); // ClapTrap damage message (from ClapTrap.cpp)
	clapTrap.beRepaired(5000); // ClapTrap reparing message (from ClapTrap.cpp)
	scavTrap.guardGate();      // ScavTrap unique function (from ScavTrap.cpp)
	for (int i = 0; i < 50; i++)
		scavTrap.beRepaired(5000);  // ClapTrap reparing message (from ClapTrap.cpp)
	scavTrap.attack(Name0);         // ScavTrap attack message (from ScavTrap.cpp)
	scavTrap.guardGate();           // ScavTrap unique function (from ScavTrap.cpp)
	scavTrap.takeDamage(5000);      // ClapTrap damage message (from ClapTrap.cpp)


/*
	ClapTrap a("AAAAAA");
	ClapTrap b("BBBBBB");
	ClapTrap c("CCCCCC");
	ClapTrap d("DDDDDD");

    ClapTrap dNew(d);
	ClapTrap dNewNew = c;

	ClapTrap defaultt;

	std::cout << "----------------" << std::endl;

	ScavTrap h("LLLLLL");
	ScavTrap o("PPPPPP");
	ScavTrap ooo(o);
	ScavTrap nnn(h);

	ScavTrap defaultttttt;
*/

    return (0);
}
