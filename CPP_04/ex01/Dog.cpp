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
    return;
}

Dog::Dog(std::string DogType) : Animal(DogType)
{
    this->type = VIOLET "🟣 Dog" RESET;
    std::cout << VIOLET "🟣 From Dog. Str constructor for " << DogType << " called" << std::endl;
    return;
}


Dog::Dog(Dog const & src) : Animal(src)
{
    std::cout << VIOLET "🟣 From Dog. Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

Dog::~Dog(void)
{
    std::cout << VIOLET "🟣 From Dog. Destructor called" RESET << std::endl;
    return;
}

/************       member functions        ***********/

void    Dog::makeSound(void) const
{
    std::cout << VIOLET "🟣 From Dog: woof woof woof" RESET << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

Dog&  Dog::operator=(Dog const & rhs)
{
    std::cout << VIOLET "🟣 From Dog. Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

// std::ostream& operator <<(std::ostream & o, Dog const & i)
// {
//     o << i.getType() << " : ";
//     return (o);
// }
