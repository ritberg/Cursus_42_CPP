/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
    return;
}

Cure::Cure(std::string const & cure) : AMateria(cure)
{
    std::cout << "Cure str constructor called" << std::endl;
    return;
}

Cure::Cure(Cure const & src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
    return;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
    return;
}   

Cure & Cure::operator=(Cure const & rhs)
{
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

/*
Create a new instance of Cure and initialize it by copying the current object (*this).
This ensures that the new instance is a deep copy of the current object, including its state */
AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return;
}
