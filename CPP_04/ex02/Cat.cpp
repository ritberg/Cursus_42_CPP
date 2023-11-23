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

Cat::Cat(void) : AAnimal()
{
    this->type = YELLOW "🟡 Cat" RESET;
    std::cout << YELLOW "🟡 From Cat. Default constructor called" RESET << std::endl;
    this->_brain = new Brain();
    return;
}

Cat::Cat(std::string CatType) : AAnimal(CatType)
{
    this->type = YELLOW "🟡 Cat" RESET;
    std::cout << YELLOW "🟡 From Cat. Str constructor for " << CatType << " called" << std::endl;
    this->_brain = new Brain();
    return;
}

Cat::Cat(Cat const & src) : AAnimal(src), _brain(NULL)
{
    std::cout << YELLOW "🟡 From Cat. Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

Cat::~Cat(void)
{
    std::cout << YELLOW "🟡 From Cat. Destructor called" RESET << std::endl;
    delete this->_brain;
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
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(rhs._brain)); 
    }
    return (*this);
}
