/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract = 8;

/* Default Constructor: Initializes the _value to 0 */
Fixed::Fixed(void) : _value(0)
{
    std::cout << "*** Default Constr *** _value is :" << _value << std::endl; //

    std::cout << "Default constructor called" << std::endl;
    return;
}

/*
Integer Constructor.
Takes an integer n and initializes the _value by left-shifting n by _fract bits
*/
Fixed::Fixed(const int n) : _value(n << _fract)
{
    std::cout << "*** Int Constr *** n is :" << n << std::endl; //
    std::cout << "*** Int Constr *** _value is :" << _value << std::endl; //

    std::cout << "Int constructor called" << std::endl;
    return;
}

/*
Float Constructor.
Takes a floating-point number nf, rounds it, and scales it by (1 << _fract).
Stores it in _value
*/
Fixed::Fixed(const float nf) : _value(round(nf * (1 << _fract)))
{
    std::cout << "*** Float constr *** nf is :" << nf << std::endl; //
    std::cout << "*** Float constr *** _value is :" << _value << std::endl; //

    std::cout << "Float constructor called" << std::endl;
    return;
}

/* Copy Constructor */
Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

/* Operator assignment overload */
Fixed&  Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
    return;
}

float   Fixed::toFloat(void) const
{
    std::cout << "*** toFloat *** _value is :" << _value << std::endl; //

    return ((float)this->_value / (1 << _fract)); 
}

int     Fixed::toInt(void) const
{
    std::cout << "*** toInt *** _value is :" << _value << std::endl; //

    return (this->_value >> Fixed::_fract);
}

std::ostream&   operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return (o);
}