/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "************ Subject tests **************" << std::endl << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    std::cout << std::endl << "---------------------------------------" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "---------------------------------------" << std::endl << std::endl;

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl << "************ More tests **************" << std::endl << std::endl;

    Character* player1 = new Character("Player1");
    Character* player2 = new Character("Player2");
    Ice* iceMateria = new Ice();
    Cure* cureMateria = new Cure();

    player1->equip(iceMateria);
    player1->equip(cureMateria);

    // Use Materias on a target character
    player1->use(0, *player2);  // Use the Materia in the first slot on player2
    player1->use(1, *player2);  // Use the Materia in the second slot on player2

    player1->unequip(1);
    player1->unequip(0);

    delete player1;
    delete player2;
    delete iceMateria;
    delete cureMateria;

/*
    std::cout << std::endl << "************ More tests 2 **************" << std::endl << std::endl;

	IMateriaSource* matSourceInterf = new MateriaSource(); // MateriaSource interface
    MateriaSource* matSource = new MateriaSource(); // MateriaSource concrete class
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Ice());

	AMateria* materias[7];

	for (int i = 0; i < 3; ++i)
		materias[i] = matSource->createMateria("ice");
	for (int i = 3; i < 6; ++i)
		materias[i] = matSource->createMateria("cure");

    std::cout << std::endl << "------------------------" << std::endl;

	ICharacter* cat = new Character("Meow"); // ICharacter interface
	ICharacter*	dog = new Character("Woof");
    Character* cat2 = new Character("Meowwwwww"); // Character concrete class
	Character*	dog2 = new Character("Wooffffff");

	std::cout << std::endl << "------------------------" << std::endl;
	for (int i = 0; i < 3; i++)
		cat->equip(materias[i]);
	for (int i = 3; i < 6; i++)
		dog->equip(materias[i]);

	cat->use(-1, *cat);
	cat->use(4, *cat);
    cat->use(0, *dog);
    cat->use(1, *dog);
	dog->use(3, *cat);
	dog->use(1, *dog);
    dog->use(8, *dog);

    std::cout << std::endl << "------------------------" << std::endl;

	delete cat;
	delete dog;
    delete cat2;
	delete dog2;
	delete matSource;
    delete matSourceInterf;
*/
    return (0);
}
