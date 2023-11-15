/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

Animal::Animal(void) : type("⚪️ This is an animal")
{
    std::cout << "⚪️ From Animal. Default constructor called" << std::endl;
    return;
}

Animal::Animal(std::string AnimalType) : type("⚪️ This is an animal")
{
    std::cout << "⚪️ From Animal. Default constructor for " << AnimalType << " called" << std::endl;
    return;
}

Animal::Animal(Animal const & src)
{
    std::cout << "⚪️ From Animal. Copy constructor called" << std::endl;
    *this = src;
    return;
}

Animal::~Animal(void)
{
    std::cout << "⚪️ From Animal. Destructor called" << std::endl;
    return;
}

/************       member functions        ***********/

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::makeSound(void) const
{
    std::cout << "⚪️ From Animal. No specific sound" << std::endl;
}

/********    Assignment and outstream operators overloads             ***********/

Animal&  Animal::operator=(Animal const & rhs)
{
    std::cout << "⚪️ From Animal. Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

// std::ostream& operator <<(std::ostream & o, Animal const & i)
// {
//     o << i.getType() << " : ";
//     return (o);
// }
