/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

WrongCat::WrongCat(void) : WrongAnimal()
{
    this->type = YELLOW "🟡🟡 Cat" RESET;
    std::cout << YELLOW "🟡🟡 From WrongCat. Default constructor called" RESET << std::endl;
    return;
}

WrongCat::WrongCat(std::string CatType) : WrongAnimal(CatType)
{
    this->type = YELLOW "🟡🟡 Cat" RESET;
    std::cout << YELLOW "🟡🟡 From WrongCat. Str constructor for " << CatType << " called" << std::endl;
    return;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
    std::cout << YELLOW "🟡🟡 From WrongCat. Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

WrongCat::~WrongCat(void)
{
    std::cout << YELLOW "🟡🟡 From WrongCat. Destructor called" RESET << std::endl;
    return;
}

/************       member functions        ***********/

void    WrongCat::makeSound(void) const
{
    std::cout << YELLOW "🟡🟡 From WrongCat. * meeeooooowwwww *" RESET << std::endl;
    return;
}

/********    Assignment and outstream operators overloads             ***********/

WrongCat&  WrongCat::operator=(WrongCat const & rhs)
{
    std::cout << YELLOW "🟡🟡 From WrongCat. Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}
