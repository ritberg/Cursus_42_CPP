/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "*   ⚪️ - parent Animal class          *" << std::endl;
	std::cout << "*   🟣 - child Dog class              *" << std::endl;
	std::cout << "*   🟡 - child Cat class              *" << std::endl;
	std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "----------Subject tests------------" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
    delete meta;

    std::cout << std::endl << "----------More tests------------" << std::endl;

    std::cout << std::endl << "[ 1 ] : Dog* test = new Dog()" << std::endl << std::endl;

    const Dog* test = new Dog();
    std::cout << test->getType() << " " << std::endl;
    test->makeSound();
    delete test;

    std::cout << std::endl << "[ 2 ] : Cat* test1 = new Cat()" << std::endl << std::endl;

	const Cat* test1 = new Cat();
    std::cout << test1->getType() << " " << std::endl;
    test1->makeSound();
    delete test1;

    std::cout << std::endl << "[ 3 ] : Animal* test2 = new Animal(str)" << std::endl << std::endl;

    const Animal* test2 = new Animal("Hohoho");
    std::cout << test2->getType() << " " << std::endl;
    test2->makeSound();
    delete test2;

    std::cout << std::endl << "[ 4 ] : Animal* test3 = new Cat(str)" << std::endl << std::endl;

    const Animal* test3 = new Cat("Mau");
    std::cout << test3->getType() << " " << std::endl;
    test3->makeSound();
    delete test3;

    std::cout << std::endl << "[ 5 ] : Animal* test4 = new Dog(str)" << std::endl << std::endl;

    const Animal* test4 = new Dog("Woof");
    std::cout << test4->getType() << " " << std::endl;
    test4->makeSound();
    delete test4;

    /* [ 6 ] : Dog* d = new Animal() - compilation error */
    // const Dog* d = new Animal();
	// d->makeSound();
	// delete d;

    std::cout << std::endl << "-------Wrong classes tests (non virtual makeSound)-------" << std::endl;

    std::cout << std::endl << "[ 1 ] : WrongAnimal* a = new WrongAnimal()" << std::endl << std::endl;

    const WrongAnimal* a = new WrongAnimal();
    std::cout << a->getType() << " " << std::endl;
    a->makeSound();
    delete a;

    std::cout << std::endl << "[ 2 ] : WrongAnimal* ac = new WrongCat()" << std::endl << std::endl;

    const WrongAnimal* ac = new WrongCat();
    std::cout << ac->getType() << " " << std::endl;
    ac->makeSound();
    delete ac;

    std::cout << std::endl << "[ 3 ] : WrongCat* c = new WrongCat()" << std::endl << std::endl;

    const WrongCat* c = new WrongCat();
    std::cout << c->getType() << " " << std::endl;
    c->makeSound();
    delete c;

    return (0);
}
