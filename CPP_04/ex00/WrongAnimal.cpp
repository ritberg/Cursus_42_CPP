/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

WrongAnimal::WrongAnimal(void) : type("⚪️⚪️ Animal")
{
    std::cout << "⚪️⚪️ From WrongAnimal. Default constructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(std::string AnimalType) : type("⚪️⚪️ " + AnimalType + " is an animal")
{
    std::cout << "⚪️⚪️ From WrongAnimal. Str constructor for " << AnimalType << " called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "⚪️⚪️ From WrongAnimal. Copy constructor called" << std::endl;
    *this = src;
    return;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "⚪️⚪️ From WrongAnimal. Destructor called" << std::endl;
    return;
}

/************       member functions        ***********/

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "⚪️⚪️ From WrongAnimal. * no specific sound *" << std::endl;
}

/********    Assignment and outstream operators overloads             ***********/

WrongAnimal&  WrongAnimal::operator=(WrongAnimal const & rhs)
{
    std::cout << "⚪️⚪️ From WrongAnimal. Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}