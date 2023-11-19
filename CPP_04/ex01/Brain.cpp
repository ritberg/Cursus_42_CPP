/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/14 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*******     Default constructor, copy constructor, destructor      ***********/

Brain::Brain(void) 
{
    std::cout << GREEN "🟢 From Brain. Default constructor called" RESET << std::endl;
    return;
}

Brain::Brain(std::string idea)
{
    std::cout << GREEN "🟢 From Brain. Str constructor called" RESET << std::endl;
    return;
}

Brain::Brain(Brain const & src)
{
    std::cout << GREEN "🟢 From Brain. Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

Brain::~Brain(void)
{
    std::cout << GREEN "🟢 From Brain. Destructor called" RESET << std::endl;
    return;
}

/************       member functions        ***********/

std::string*    Brain::getIdeas(void)
{
    return (this->_ideas);
}

void    Brain::setIdeas(std::string idea, int i)
{
    if (i >= 0 && i < 100)
        _ideas[i] = idea;
}

/********    Assignment and outstream operators overloads             ***********/

/*
The overloaded assignment operator is responsible for performing a deep copy of the Brain object.
It checks for self-assignment (this != &rhs) to avoid unnecessary work.
It then copies each element of the ideas array individually to ensure a deep copy.
*/
Brain&  Brain::operator=(Brain const & rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; ++i)
            this->_ideas[i] = rhs._ideas[i];
    }
    return (*this);
}