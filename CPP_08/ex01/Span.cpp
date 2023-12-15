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

int Span::shortestSpan(void)
{
    // std::ofstream   ofs("big_array");

    if (this->_arr.size() < 2)
        throw std::out_of_range("Error: array is too small to find the shortest span");
    std::vector<int> sortedArr = this->_arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    int minSpan = std::numeric_limits<int>::max();

    for (std::vector<int>::const_iterator it = sortedArr.begin() + 1; it != sortedArr.end(); ++it)
    {
        int currentSpan = *it - *(it - 1);
        minSpan = std::min(minSpan, currentSpan);
        // if (this->_arr.size() > 100)
        //     ofs << *it << " - " << *(it - 1) << " = " << currentSpan << std::endl;
        // else
        //     std::cout << *it << " - " << *(it - 1) << " = " << currentSpan << std::endl;
    }
    return (minSpan);
}

int Span::longestSpan(void)
{
    if (this->_arr.size() < 2)
        throw std::out_of_range("Error: array is too small to find the longest span");
    std::vector<int>::iterator min = std::min_element(this->_arr.begin(), this->_arr.end());
    std::vector<int>::iterator max = std::max_element(this->_arr.begin(), this->_arr.end());
    return (*max - *min);
}

 void   Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    unsigned int rangeSize = std::distance(begin, end);

    if (this->_arr.size() + rangeSize <= _maxN)
        this->_arr.insert(_arr.end(), begin, end);
    else
        throw std::out_of_range("Error: adding the range would exceed the maximum capacity");
}

std::ostream &	operator<<(std::ostream &out, Span & obj)
{
    out << obj; //TO DO
    return (out);
}
