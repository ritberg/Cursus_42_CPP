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
#include "Brain.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "*   ⚪️ - parent Animal class          *" << std::endl;
	std::cout << "*   🟣 - child Dog class              *" << std::endl;
	std::cout << "*   🟡 - child Cat class              *" << std::endl;
	std::cout << "***************************************" << std::endl << std::endl;

    std::cout << std::endl << "**** **** **** OLD **** **** ****" << std::endl << std::endl;

    std::cout << "----------Subject tests------------" << std::endl << std::endl;

	// const AAnimal* meta = new AAnimal(); //non instanciable! error: allocating an object of abstract class type 'AAnimal'
	const AAnimal* j = new Dog(); // I can create an object derived from AAnimal class. This is a form of polymorphism
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound(); //non instanciable! error: allocating an object of abstract class type 'AAnimal'
	delete j;
	delete i;
    // delete meta; //non instanciable! error: allocating an object of abstract class type 'AAnimal'

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

    // const AAnimal* test2 = new AAnimal("Hohoho"); //non instanciable! error: allocating an object of abstract class type 'AAnimal'
    // std::cout << test2->getType() << " " << std::endl;
    // test2->makeSound();
    // delete test2;

    std::cout << std::endl << "[ 4 ] : Animal* test3 = new Cat(str)" << std::endl << std::endl;

    const AAnimal* test3 = new Cat("Mau");
    std::cout << test3->getType() << " " << std::endl;
    test3->makeSound();
    delete test3;

    std::cout << std::endl << "[ 5 ] : Animal* test4 = new Dog(str)" << std::endl << std::endl;

    const AAnimal* test4 = new Dog("Woof");
    std::cout << test4->getType() << " " << std::endl;
    test4->makeSound();
    delete test4;


    std::cout << std::endl << "**** **** **** NEW EX01 TESTS **** **** ****" << std::endl << std::endl;

    std::cout << std::endl << "---------An animal table with half cats, half dogs---------" << std::endl << std::endl;

    // AAnimal animal[6]; //non instanciable! error: array of abstract class type 'AAnimal'

    // for (int i = 0; i < 3; ++i)
    //     animal[i] = Dog();
    // for (int i = 3; i < 6; ++i)
    //     animal[i] = Cat();

    std::cout << std::endl << "---------Copy of the cat/dog and the original cat/dog---------" << std::endl << std::endl;

  
    Cat originalCat("Persian");
    Cat copiedCat = originalCat; // Make a copy of the Cat

    Dog originalDog("Golden Retriever");
    Dog copiedDog = originalDog; // Make a copy of the Dog

    std::cout << "Original Cat: " << std::endl;
    originalCat.makeSound();
    std::cout << "Type: " << originalCat.getType() << std::endl;
    std::cout << "Original Cat Brain Address: " << originalCat.getBrain() << std::endl;

    std::cout << std::endl << "Copied Cat: " << std::endl;
    copiedCat.makeSound();
    std::cout << "Type: " << copiedCat.getType() << std::endl;
    std::cout << "Copied Cat Brain Address: " << copiedCat.getBrain() << std::endl;

    std::cout << std::endl << "Original Dog: " << std::endl;
    originalDog.makeSound();
    std::cout << "Type: " << originalDog.getType() << std::endl;
    std::cout << "Original Dog Brain Address: " << originalDog.getBrain() << std::endl;

    std::cout << std::endl << "Copied Dog: " << std::endl;
    copiedDog.makeSound();
    std::cout << "Type: " << copiedDog.getType() << std::endl;
    std::cout << "Copied Dog Brain Address: " << copiedDog.getBrain() << std::endl;

    std::cout << std::endl << "---------Set ideas in Brain class and in Dog and Cat classes---------" << std::endl << std::endl;

    std::cout << std::endl << "[ 1 ] : set and get ideas in Brain class" << std::endl << std::endl;

    Brain brain1;
    brain1.setIdeas("interesting idea", 0);
    brain1.setIdeas("stupid idea", 4);
    brain1.setIdeas("new idea", 37);

    std::string *ideas = brain1.getIdeas();
    for (int i = 0; i < 100; ++i)
    {
        std::cout << "Idea " << i + 1 << " : ";
        std::cout << ideas[i] << " " << std::endl;
    }

    std::cout << std::endl << "[ 2 ] : set and get ideas in Dog class" << std::endl << std::endl;

    Dog* gaffe = new Dog();
    gaffe->getBrain()->setIdeas("interesting idea", 0);
    std::string* gaffeIdeas = gaffe->getBrain()->getIdeas();
    std::cout << "Dog Idea: ";
    for (int i = 0; i < 100; ++i)
        std::cout << gaffeIdeas[i];
    std::cout << std::endl;
    delete gaffe;

    std::cout << std::endl << "[ 3 ] : set and get ideas in Cat class" << std::endl << std::endl;

    Cat* miau = new Cat();
    miau->getBrain()->setIdeas("stupid idea", 4);
    std::string* miauIdeas = miau->getBrain()->getIdeas();
    std::cout << "Cat Idea: ";
    for (int i = 0; i < 100; ++i)
        std::cout << miauIdeas[i];
    std::cout << std::endl;
    delete miau;

    std::cout << std::endl << "----- Destructors-----" << std::endl << std::endl;

    return (0);
}
