/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

Cat::Cat(void) : Animal()
{
    this->_brain = new Brain();
    this->type = YELLOW "🟡 Cat" RESET;
    std::cout << YELLOW "🟡 From Cat. Default constructor called" RESET << std::endl;
    return;
}

Cat::Cat(std::string CatType) : Animal(CatType)
{
    this->_brain = new Brain();
    this->type = YELLOW "🟡 Cat" RESET;
    std::cout << YELLOW "🟡 From Cat. Str constructor for " << CatType << " called" << std::endl;
    return;
}

/*
    this->_brain = new Brain(*(src._brain)) creates a new Brain object by
    dereferencing the source Cat object's _brain pointer and copying its contents.
*/
Cat::Cat(Cat const & src) : Animal(src)
{
    this->_brain = new Brain(*(src._brain));  // Creating a new Brain object with a copy of the source Brain
    std::cout << YELLOW "🟡 From Cat. Copy constructor called" RESET << std::endl;
    return;
}

Cat::~Cat(void)
{
    delete this->_brain;
    std::cout << YELLOW "🟡 From Cat. Destructor called" RESET << std::endl;
    return;
}

/************       member functions        ***********/

void    Cat::makeSound(void) const
{
    std::cout << YELLOW "🟡 From Cat. * meeeooooowwwww *" RESET << std::endl;
    return;
}

Brain*   Cat::getBrain(void) const
{
    return (this->_brain);
}

/********    Assignment and outstream operators overloads             ***********/

Cat&  Cat::operator=(Cat const & rhs)
{
    std::cout << YELLOW "🟡 From Cat. Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
        delete this->_brain;  // Delete the existing Brain object
        this->_brain = new Brain(*(rhs._brain));  // Create a new Brain object with a copy of the source Brain
    }
    return (*this);
}
