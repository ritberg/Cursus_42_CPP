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

MateriaSource::MateriaSource(void) : count(0)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL; // Initialize the array to NULL
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL; // Initialize the array to NULL
    *this = src;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;  
    for (int i = 0; i < count; ++i)
        delete inventory[i];  // delete dynamically allocated AMateria objects
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // Copy the contents of rhs.inventory to this->inventory
        for (int i = 0; i < rhs.count; ++i)
            inventory[i] = rhs.inventory[i]->clone();

        count = rhs.count; // Update the count
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    // Error handling for a full array
    if (count < 4)
        inventory[count++] = materia;
    else
        std::cout << "Inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < count; ++i)
    {
        if (inventory[i] != NULL && inventory[i]->getType() == type)
            return inventory[i]->clone(); // Return a new instance of the same type
    }
    return NULL;
}
