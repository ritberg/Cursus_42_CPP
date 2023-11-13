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
#include "FragTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "*   ⚪️ - parent ClapTrap class        *" << std::endl;
	std::cout << "*   🟣 - child ScavTrap class         *" << std::endl;
	std::cout << "*   🟡 - child FragTrap class         *" << std::endl;
	std::cout << "***************************************" << std::endl << std::endl;

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

    std::cout << std::endl;

	// Creating an instance of ScavTrap
    ScavTrap scav("ScavTrapInstance");
    scav.attack("Target 2");
    scav.takeDamage(15);
    scav.beRepaired(5);

	std::cout << std::endl;

	// Creating an instance of FragTrap
	FragTrap frag("Test");
	frag.highFivesGuys();
    frag.takeDamage(100);
    frag.highFivesGuys(); // impossible to ask for high fives if 0 hit points left

	std::cout << "--------------------------" << std::endl;
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

	std::cout << "--------------------------" << std::endl << std::endl;

	FragTrap	fragTrap(Name0);
	fragTrap.attack(Name1);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(100);
	fragTrap.highFivesGuys();
	fragTrap.attack(Name1);

	std::cout << "--------------------------" << std::endl << std::endl;

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
	FragTrap o("PPPPPP");
	FragTrap ooo(o);
	ScavTrap nnn(h);
*/

    return (0);
}
