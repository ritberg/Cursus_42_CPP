/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

Dog::Dog(void) : AAnimal()
{
    this->_brain = new Brain();
    this->type = VIOLET "🟣 Dog" RESET;
    std::cout << VIOLET "🟣 From Dog. Default constructor called" RESET << std::endl;
    return;
}

Dog::Dog(std::string DogType) : AAnimal(DogType)
{
    this->_brain = new Brain();
    this->type = VIOLET "🟣 Dog" RESET;
    std::cout << VIOLET "🟣 From Dog. Str constructor for " << DogType << " called" << std::endl;
    return;
}


Dog::Dog(Dog const & src) : AAnimal(src)
{
    this->_brain = new Brain(*(src._brain));  // Creating a new Brain object with a copy of the source Brain
    std::cout << VIOLET "🟣 From Dog. Copy constructor called" RESET << std::endl;
    return;
}

Dog::~Dog(void)
{
    delete this->_brain;
    std::cout << VIOLET "🟣 From Dog. Destructor called" RESET << std::endl;
    return;
}

/************       member functions        ***********/

void    Dog::makeSound(void) const
{
    std::cout << VIOLET "🟣 From Dog. * woof woof woof *" RESET << std::endl;
    return;
}

Brain*   Dog::getBrain(void) const
{
    return (this->_brain);
}

/********    Assignment and outstream operators overloads             ***********/

Dog&  Dog::operator=(Dog const & rhs)
{
    std::cout << VIOLET "🟣 From Dog. Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
        delete this->_brain;  // Delete the existing Brain object
        this->_brain = new Brain(*(rhs._brain));  // Create a new Brain object with a copy of the source Brain
    }
    return (*this);
}
