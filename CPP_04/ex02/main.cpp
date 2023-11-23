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

    std::cout << "**** **** **** OLD **** **** ****" << std::endl << std::endl;

    std::cout << "----------Subject tests------------" << std::endl << std::endl;

	// const AAnimal* meta = new AAnimal(); //non instanciable! error: allocating an object of abstract class type 'AAnimal'
	const AAnimal* j = new Dog(); // I can create an object derived from AAnimal class. This is a form of polymorphism
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();
	delete j;
	delete i;
    // delete meta;

    std::cout << std::endl << "----------More tests------------" << std::endl;

    std::cout << std::endl << "[ 1 ] : Dog* test1 = new Dog()" << std::endl << std::endl;

    const Dog* test1 = new Dog();
    std::cout << test1->getType() << " " << std::endl;
    test1->makeSound();
    delete test1;

    std::cout << std::endl << "[ 2 ] : Cat* test2 = new Cat()" << std::endl << std::endl;

	const Cat* test2 = new Cat();
    std::cout << test2->getType() << " " << std::endl;
    test2->makeSound();
    delete test2;

    std::cout << std::endl << "[ 3 ] : Animal* test3 = new Animal(str) - impossible" << std::endl << std::endl;

    // const AAnimal* test3 = new AAnimal("Hohoho");  //non instanciable! error: allocating an object of abstract class type 'AAnimal'
    // std::cout << test3->getType() << " " << std::endl;
    // test3->makeSound();
    // delete test3;

    std::cout << std::endl << "[ 4 ] : Animal* test4 = new Cat(str)" << std::endl << std::endl;

    const AAnimal* test4 = new Cat("Mau");
    std::cout << test4->getType() << " " << std::endl;
    test4->makeSound();
    delete test4;

    std::cout << std::endl << "[ 5 ] : Animal* test5 = new Dog(str)" << std::endl << std::endl;

    const AAnimal* test5 = new Dog("Woof");
    std::cout << test5->getType() << " " << std::endl;
    test5->makeSound();
    delete test5;

    std::cout << std::endl << "**** **** **** NEW EX01 TESTS **** **** ****" << std::endl << std::endl;

    std::cout << std::endl << "---------An animal table with half cats, half dogs---------" << std::endl << std::endl;

/*
It works ! Pointers to the base class can be used to point to objects of derived classes.

This array animal can store pointers to objects of any class derived from AAnimal.
The new Dog() and new Cat() statements allocate memory for objects of the derived classes
Dog and Cat and return pointers to the base class AAnimal.
*/
    AAnimal *animal[6];
    std::cout << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        animal[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = 3; i < 6; ++i)
    {
        animal[i] = new Cat();
        std::cout << std::endl;
    }
    for (int i = 0; i < 6; ++i)
    {
        delete animal[i];
        std::cout << std::endl;
    }
  
    std::cout << std::endl << "---------Copy of the cat/dog and the original cat/dog---------" << std::endl << std::endl;

    Cat originalCat("Persian");
    Cat copiedCat = originalCat;

    Dog originalDog("Golden Retriever");
    Dog copiedDog = originalDog;

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

    std::cout << std::endl << "---------Set ideas in Brain class and in Dog and Cat classes---------" << std::endl;

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
    int indexx = 0;
    gaffe->getBrain()->setIdeas("interesting idea", indexx);
    std::string* gaffeIdeas = gaffe->getBrain()->getIdeas();
    std::cout << "Dog Idea " << indexx << " : ";
    for (int i = 0; i < 100; ++i)
        std::cout << gaffeIdeas[i];
    std::cout << std::endl;
    delete gaffe;

    std::cout << std::endl << "[ 3 ] : set and get ideas in Cat class" << std::endl << std::endl;

    Cat* miau = new Cat();
    indexx = 4;
    miau->getBrain()->setIdeas("stupid idea", indexx);
    std::string* miauIdeas = miau->getBrain()->getIdeas();
    std::cout << "Cat Idea " << indexx << " : ";
    for (int i = 0; i < 100; ++i)
        std::cout << miauIdeas[i];
    std::cout << std::endl;
    delete miau;
    
    std::cout << std::endl << "------Evaluation sheet tests----------" << std::endl << std::endl;

    // AAnimal test0;

    std::cout << std::endl << "----- Destructors-----" << std::endl << std::endl;

    return (0);
}
