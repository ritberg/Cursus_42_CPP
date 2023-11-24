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

    std::cout << std::endl << "[ 3 ] : Animal* test3 = new Animal(str)" << std::endl << std::endl;

    const Animal* test3 = new Animal("Hohoho");
    std::cout << test3->getType() << " " << std::endl;
    test3->makeSound();
    delete test3;

    std::cout << std::endl << "[ 4 ] : Animal* test4 = new Cat(str)" << std::endl << std::endl;

    const Animal* test4 = new Cat("Mau");
    std::cout << test4->getType() << " " << std::endl;
    test4->makeSound();
    delete test4;

    std::cout << std::endl << "[ 5 ] : Animal* test5 = new Dog(str)" << std::endl << std::endl;

    const Animal* test5 = new Dog("Woof");
    std::cout << test5->getType() << " " << std::endl;
    test5->makeSound();
    delete test5;

    /* [ 6 ] : Dog* d = new Animal() - compilation error */
    // const Dog* d = new Animal();
	// d->makeSound();
	// delete d;


    std::cout << std::endl << "**** **** **** NEW EX01 TESTS **** **** ****" << std::endl << std::endl;

    std::cout << std::endl << "---------An animal table with half cats, half dogs---------" << std::endl << std::endl;

    Animal *animal[6];
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
  
    std::cout << "---------Copy of the cat/dog and the original cat/dog---------" << std::endl << std::endl;

    /*
    The Brain objects of the original and copied objects should have different addresses, because they are distinct objects in memory.
    Additionally, modifying one object (ex, adding an idea to the Brain) should not affect the other object.
    */
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
    /*
    Each component is copied individually (The Dog object is copied, and it involves the copy constructor
        of Animal, the copy assignment operator of Animal, the copy constructor of Brain,
        and the copy constructor of Dog).

    In a shallow copy, the copy process would involve copying the values of pointers
        to the same memory locations, i.e. the copied object and the original object would share
        the same underlying data. In a deep copy, each component of the object is duplicated,
        creating new, independent copies.

    The fact that there are calls to copy constructors and destructors for each component
        (Animal, Brain, and Dog) suggests that a deep copy is taking place. 
    */

    std::cout << std::endl << "[ 1 ] dog" << std::endl << std::endl;

    Dog basic;
    { Dog tmp = basic; }

    std::cout << std::endl << "[ 2 ] cat" << std::endl << std::endl;

    Cat basic1;
    { Cat tmp1 = basic1; }

    std::cout << std::endl << "----- Destructors-----" << std::endl << std::endl;

    return (0);
}
