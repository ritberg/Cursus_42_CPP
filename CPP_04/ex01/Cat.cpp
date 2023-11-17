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

Cat::Cat(void) : Animal()
{
    _brain = new Brain();
    this->type = YELLOW "🟡 Cat" RESET;
    std::cout << YELLOW "🟡 From Cat. Default constructor called" RESET << std::endl;
    return;
}

Cat::Cat(std::string CatType) : Animal(CatType)
{
    _brain = new Brain();
    this->type = YELLOW "🟡 Cat" RESET;
    std::cout << YELLOW "🟡 From Cat. Str constructor for " << CatType << " called" << std::endl;
    return;
}

Cat::Cat(Cat const & src) : Animal(src)
{
    std::cout << YELLOW "🟡 From Cat. Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << YELLOW "🟡 From Cat. Destructor called" RESET << std::endl;
    return;
}

/************       member functions        ***********/

void    Cat::makeSound(void) const
{
    std::cout << YELLOW "🟡 From Cat: meeeooooowwwww " RESET << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

Cat&  Cat::operator=(Cat const & rhs)
{
    std::cout << YELLOW "🟡 From Cat. Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

// std::ostream& operator <<(std::ostream & o, Cat const & i)
// {
//     o << i.getType() << " : ";
// }
