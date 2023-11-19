/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

AAnimal::AAnimal(void) : type("⚪️ Animal")
{
    std::cout << "⚪️ From AAnimal. Default constructor called" << std::endl;
    return;
}

AAnimal::AAnimal(std::string AnimalType) : type("⚪️ " + AnimalType + " is an animal")
{
    std::cout << "⚪️ From AAnimal. Str constructor for " << AnimalType << " called" << std::endl;
    return;
}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "⚪️ From AAnimal. Copy constructor called" << std::endl;
    *this = src;
    return;
}

AAnimal::~AAnimal(void)
{
    std::cout << "⚪️ From AAnimal. Destructor called" << std::endl;
    return;
}

/************       member functions        ***********/

std::string AAnimal::getType(void) const
{
    return (this->type);
}

void    AAnimal::makeSound(void) const
{
    std::cout << "⚪️ From AAnimal. * no specific sound *" << std::endl;
}

/********    Assignment and outstream operators overloads             ***********/

AAnimal&  AAnimal::operator=(AAnimal const & rhs)
{
    std::cout << "⚪️ From AAnimal. Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}
