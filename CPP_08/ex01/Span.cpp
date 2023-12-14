/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(unsigned int N) : _maxN(N)
{
}

Span::~Span(void)
{
}

Span&  Span::operator=(Span const & rhs)
{
    if (this != &rhs)
        this->_maxN = rhs._maxN;
    return (*this);
}

std::vector<int>& Span::getArr(void) 
{
    return (this->_arr);
}

void Span::addNumber(unsigned int newN)
{
    if (this->_arr.size() < this->_maxN)
        this->_arr.push_back(newN);
    else
        throw std::out_of_range("Error: array is already full");
    
}

void Span::shortestSpan()
{
    std::vector<int>::iterator minElem = std::min_element(this->_arr.begin(), this->_arr.end(), Less<int>());
    std::cout << "Min Element: " << *minElem << std::endl; //why no output??

}

std::ostream &	operator<<(std::ostream &out, Span & obj)
{
    out << obj; //TO DO
    return (out);
}
