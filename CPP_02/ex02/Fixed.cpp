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
    return;
}

/* Copy Constructor */
Fixed::Fixed(Fixed const & src)
{
    *this = src;
    return;
}

Fixed::~Fixed(void)
{
    return;
}

/* Operator assignment overload */
Fixed&  Fixed::operator=(Fixed const & rhs)
{
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

/*********************************************************************** 
*********    NEW DECLARATIONS (in comparison with ex01)   **************
***********************************************************************/

/*             Arithmetic operator overloads                           */

/*
How does it work ?

Example of Fixed const b(Fixed(5.05f) * Fixed(2)) from main.cpp.
`5.05 * 256 = 1292.8` (`1293` rounded)
2 doesn't change (because 2 * 256 = 512 then 512 /256 = 2).
`1293 * 2 = 2586`
`2586 / 256 = 10.1016 (rounded)`

Example of Fixed const b(Fixed(5.05f) + Fixed(2)) from main.cpp. 
`5.05 * 256 = 1292.8` (`1293` rounded)
2 doesn't change
`1293 + 512 = 1805`
`1805 / 256 = 7.05078`
*/
Fixed  Fixed::operator+(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed  Fixed::operator-(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed  Fixed::operator*(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed  Fixed::operator/(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

/*            Comparison operator overloads                             */

bool    Fixed::operator>(Fixed const & rhs) const
{
    if (this->_value > rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<(Fixed const & rhs) const
{
    if (this->_value < rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator>=(Fixed const & rhs) const
{
    if (this->_value >= rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<=(Fixed const & rhs) const
{
    if (this->_value <= rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator==(Fixed const & rhs) const
{
    if (this->_value == rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator!=(Fixed const & rhs) const
{
    if (this->_value != rhs.getRawBits())
        return (true);
    return (false);
}

/*                   Increment/decrement operator overloads             */

/*
Prefix addition ++a :
The prefix increment operator increments the value `a`
and returns a reference to the modified object.
*/
Fixed&  Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}

/*
Postfix addition a++ :
The postfix increment operator also increments the value of `a`.

Decrement the value of the current object *this using --(*this).
The value of temp is created as a copy of the original object before the decrement operation.
The post-decrement operator returns the original value of the object (i.e., temp) before the decrement.
*/
Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);
    ++(*this);
    return (temp);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);
    --(*this);
    return (temp);
}

/*                    Max and min functions                               */

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}
