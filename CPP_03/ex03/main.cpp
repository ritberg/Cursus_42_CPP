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
#include "DiamondTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "*   ⚪️ - parent ClapTrap class        *" << std::endl;
	std::cout << "*   🟣 - child ScavTrap class         *" << std::endl;
	std::cout << "*   🟡 - child FragTrap class         *" << std::endl;
	std::cout << "*   🟢 - the top DiamondTrap class    *" << std::endl;
	std::cout << "***************************************" << std::endl << std::endl;


	DiamondTrap diam("Diamond");
	DiamondTrap def;

	std::cout << std::endl << "------------------------" << std::endl;
	diam.whoAmI();        //whoAmI() comes from DiamondTrap.cpp
	diam.attack("Enemy"); //attack() comes from ScavTrap.cpp
	def.whoAmI();         //whoAmI() comes from DiamondTrap.cpp

	std::cout << std::endl << "-------------------------" << std::endl;
	diam.takeDamage(1000); // damage message (from ClapTrap.cpp)
	diam.attack("Enemy"); //attack() (from ScavTrap.cpp)

	for (int i = 0; i < 51; i++)
		def.attack("Enemy"); //attack() comes from ScavTrap.cpp


	std::cout << std::endl << "-------------------------" << std::endl;


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

	std::cout << "----------------" << std::endl;
	
	DiamondTrap hihi("DIAMOND");
	DiamondTrap hoho(hihi);
	DiamondTrap huhu = hihi;
*/

    return (0);
}
