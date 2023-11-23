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

Dog::Dog(void) : Animal()
{
    this->type = VIOLET "🟣 Dog" RESET;
    std::cout << VIOLET "🟣 From Dog. Default constructor called" RESET << std::endl;
    this->_brain = new Brain();
    return;
}

Dog::Dog(std::string DogType) : Animal(DogType)
{
    this->type = VIOLET "🟣 Dog" RESET;
    std::cout << VIOLET "🟣 From Dog. Str constructor for " << DogType << " called" << std::endl;
    this->_brain = new Brain();
    return;
}

/* _brain in tmp = NULL because tmp should be created (cf. test { Dog tmp = basic; }) */
Dog::Dog(Dog const & src) : Animal(src), _brain(NULL)
{
    std::cout << VIOLET "🟣 From Dog. Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

Dog::~Dog(void)
{
    std::cout << VIOLET "🟣 From Dog. Destructor called" RESET << std::endl;
    delete this->_brain;
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
        if (this->_brain)
            delete this->_brain;  // Delete the existing Brain object
        this->_brain = new Brain(*(rhs._brain));  // Create a new Brain object with a copy of the source Brain
    }
    return (*this);
}
