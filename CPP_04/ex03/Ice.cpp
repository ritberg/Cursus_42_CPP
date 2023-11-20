/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
    return;
}

Ice::Ice(std::string const & ice) : AMateria(ice)
{
    std::cout << "Ice str constructor called" << std::endl;
    return;
}

Ice::Ice(Ice const & src)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
    return;
}   

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
    return;
}   

Ice & Ice::operator=(Ice const & rhs)
{
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

/*
Create a new instance of Ice and initialize it by copying the current object (*this).
This ensures that the new instance is a deep copy of the current object, including its state */
AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}
