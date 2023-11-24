/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _count(0), _inventory()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) : _inventory()
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;  
    for (int i = 0; i < _count; ++i)
        delete _inventory[i];  // delete dynamically allocated AMateria objects
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < rhs._count; ++i)   // Copy the contents of rhs.inventory to this->inventory
            _inventory[i] = rhs._inventory[i]->clone();

        _count = rhs._count; // Update the count
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (_count < 4)
        _inventory[_count++] = materia;
    else
        std::cout << "Inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _count; ++i)
    {
        if (i >= _count) //
            return (NULL); //
        if (_inventory[i] != NULL && _inventory[i]->getType() == type)
            return (_inventory[i]->clone()); // Return a new instance of the same type
    }
    return (NULL);
}
