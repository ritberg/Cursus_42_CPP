/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("default")
{
    std::cout << "AMateria default constructor called" << std::endl;
    return;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria str constructor for " << type << " called" << std::endl;
    return;
}

AMateria::AMateria(AMateria const & src)
{
    std::cout << "AMateria copy constructor for " << this->type <<" called" << std::endl;
    *this = src;
    return;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor " << this->type << " called" << std::endl;
    return;
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* shoots an Materia bolt at " << target.getName() << " *" << std::endl;
    return;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}
