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
	std::cout << "    No color - parent ClapTrap class   " << std::endl;
	std::cout << "    🟣 - child ScavTrap class          " << std::endl;
	std::cout << "    🟡 - child FragTrap class          " << std::endl;
	std::cout << "***************************************" << std::endl << std::endl;


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

	FragTrap frag("Test");
	frag.highFivesGuys();


/*
	std::string Name0 = "000";
	std::string Name1 = "111";

	ScavTrap	scavTrap(Name0);
	ClapTrap	clapTrap(Name1);

	clapTrap.attack(Name0);
	scavTrap.takeDamage(0);
	scavTrap.attack(Name1);
	clapTrap.takeDamage(20);
	clapTrap.beRepaired(5000);
	scavTrap.guardGate();
	for (int i = 0; i < 50; i++)
		scavTrap.beRepaired(5000);
	scavTrap.attack(Name0);
	scavTrap.guardGate();
	scavTrap.takeDamage(5000);
*/

/*
	std::string Name0 = "000";
	std::string Name1 = "111";

	ClapTrap	trap0(Name0);
	ClapTrap	trap1(Name1);
    
	trap0.beRepaired(0);
	for (int i = 0; i < 9; i++)
		trap0.attack(Name1);
	trap0.attack(Name1);  //impossible: 000 has too few energy points to attack
	trap1.takeDamage(5);
	trap1.beRepaired(4);
	trap1.attack(Name0);
	trap0.takeDamage(5);    //impossible: 000 cannot take damage: there are no energy points left
	trap0.beRepaired(5000); //impossible: 000 cannot be repaired: there are no energy points left
	trap1.beRepaired(5000); //impossible: 111 cannot be repaired: it will have more than 10 points
	trap1.attack(Name1);    //impossible: 111 cannot attack itself
	trap1.takeDamage(5000); //impossible: 111 cannot take damage: hit points cannot become negative
	trap1.beRepaired(5000); //impossible: 111 cannot be repaired: it will have more than 10 points
	trap1.takeDamage(1);
*/

/*
    ClapTrap a;
    ClapTrap b("Cody");

	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
*/
/*

	ClapTrap a("AAAAAA"); //why copy constructor and assignment operator don't work for a?
	ClapTrap b("BBBBBB"); //why copy constructor and assignment operator don't work for b?
	ClapTrap c("CCCCCC");
	ClapTrap d("DDDDDD");
    ClapTrap dNew(d);
	ClapTrap dNewNew = c;
	ClapTrap defaultt;
*/

    return (0);
}
