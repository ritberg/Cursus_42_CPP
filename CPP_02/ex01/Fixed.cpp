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

/* Default Constructor: Initializes the `_value` to 0. */
Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

/*
Integer Constructor.
Takes an integer `n` and does left-shifting by `_fract` bits (by 8).

10 would be 2560 because 10 << 8 = 2560 (cf. Fixed const b(10) in main.cpp).
_value = 2560.
*/
Fixed::Fixed(const int n) : _value(n << _fract)
{
    std::cout << "Int constructor called" << std::endl;
    return;
}

/*
Float Constructor.
Takes a floating-point number `nf`, rounds it, and scales it by `1 << _fract` (1 << 8).

1 << 8 = 256 in decimal or 100000000 in binary.
42.42 would be 10860 because round(42.42 * 256) = 10860 (cf. Fixed const c(42.42f) in main.cpp).
_value = 10860.
*/
Fixed::Fixed(const float nf) : _value(round(nf * (1 << _fract)))
{
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

/*  
Example of 42.42.

1 << 8 = 256 in decimal or 100000000 in binary.
If 42.42 is stored as a fixed-point number by multiplying it by 256
(_fract is 8), _value = 10860 (rounded).
To convert 10860 back to 42.42, we need to divide it by 256
to reverse the scaling operation.
*/
float   Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << _fract)); 
}

/*
Shifting to the right by _fract positions removes the fractional bits
and leaves only the integer part of the fixed-point value. 

Example: 10860 >> 8 = 42 (cf. Fixed const c(42.42f) in main.cpp).
*/
int     Fixed::toInt(void) const
{
    return (this->_value >> Fixed::_fract);
}

std::ostream&   operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return (o);
}

/* Prints */
/*
std::cout << "*** Default Constr *** _value is : " << _value << std::endl; //

std::cout << "*** Int Constr *** n is : " << n << std::endl; //
std::cout << "*** Int Constr *** _value is : " << _value << std::endl; //
std::cout << "*** Float constr *** nf is : " << nf << std::endl; //
std::cout << "*** Float constr *** _value is : " << _value << std::endl; //

std::cout << "*** toFloat *** _value is : " << _value << std::endl; //
std::cout << "*** toInt *** _value is : " << _value << std::endl; //
*/