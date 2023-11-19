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

    /* [ 6 ] : Dog* d = new Animal() - compilation error: cannot initialize a variable of type 'const Dog *' with an rvalue of type 'Animal * */
    // const Dog* d = new Animal();
	// d->makeSound();
	// delete d;

    std::cout << std::endl << "-------Wrong classes tests (non virtual makeSound)-------" << std::endl;

    std::cout << std::endl << "[ 1 ] : WrongAnimal* wa = new WrongAnimal()" << std::endl << std::endl;

    const WrongAnimal* wa = new WrongAnimal();
    std::cout << wa->getType() << " " << std::endl;
    wa->makeSound(); 
    delete wa;

    std::cout << std::endl << "[ 2 ] : WrongAnimal* wac = new WrongCat()" << std::endl << std::endl;

    /*
    Without the virtual keyword for the makeSound() function in the base class (WrongAnimal),
    the function is determined by the type of the pointer, not the actual type of the object (WrongCat). 

    When using a pointer to the base class,
    it calls the function from the base class 
    */
    const WrongAnimal* wac = new WrongCat();
    std::cout << wac->getType() << " " << std::endl;
    wac->makeSound(); // it will print * no specific sound * instead of * meeeooooowwwww * 
    delete wac;

    std::cout << std::endl << "[ 3 ] : WrongCat* wc = new WrongCat()" << std::endl << std::endl;

    /*
    When using a pointer to the derived class,
    it calls the function from the derived class.
    */
    const WrongCat* wc = new WrongCat();
    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound();  // it will print * meeeooooowwwww *
    delete wc;

    return (0);
}