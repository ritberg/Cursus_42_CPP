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

/********    Assignment and outstream operators overloads             ***********/

Brain&  Brain::operator=(Brain const & rhs)
{
    // for (int i = 0; i < 100; i++)
    // {
    //     if (this != &rhs)
    //     this->_ideas[i] = rhs.getIdeas();
    // }
    return (*this);
}