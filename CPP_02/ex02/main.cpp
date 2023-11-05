/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Fixed.hpp"

int main(void)
{
/*             Main subject tests                                      */

	Fixed 			a;
	Fixed const		b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;


/*             Arithmetic operator tests                           */

    std::cout << std::endl;
    std::cout << "****** Arithmetic operator tests ******" << std::endl << std::endl;

	Fixed const s(Fixed(5.05f) / Fixed(2));
	Fixed const r(Fixed(5.05f) + Fixed(2));
	Fixed const o(Fixed(5.05f) - Fixed(2));
    Fixed const j(Fixed(-5.05f) + Fixed(2));

    std::cout << "s = 5.05f after / 2 : " << s << std::endl;
    std::cout << "r = 5.05f after + 2 : " << r << std::endl;
    std::cout << "o = 5.05f after - 2 : " << o << std::endl;
    std::cout << "j = -5.05f after + 2 : " << j << std::endl;

/*             Comparison operator tests                           */

    std::cout << std::endl;
    std::cout << "****** Comparison operator tests ******" << std::endl << std::endl;

    Fixed l(42.42f);
    Fixed p;

    std::cout << "l is : " << l << std::endl;
    std::cout << "p is : " << p << std::endl;

    std::boolalpha(std::cout);
    std::cout << "l > p is " << (l > p) << std::endl;
    std::cout << "l < p is " << (l < p) << std::endl;
    std::cout << "l >= p is " << (l >= p) << std::endl;
    std::cout << "l <= p is " << (l <= p) << std::endl;
    std::cout << "l = p is " << (l == p) << std::endl;
    std::cout << "l != p is " << (l != p) << std::endl;

/*                   Increment/decrement operator tests             */

    std::cout << std::endl;
    std::cout << "****** Increment/decrement operator tests ******" << std::endl << std::endl;

    Fixed m(10.11f);
    std::cout << "m : " << m << std::endl;

	std::cout << "++m : " <<  ++m << std::endl;
	std::cout << "m now is : " << m << std::endl;
	std::cout << "m++ : " << m++ << std::endl;
	std::cout << "m now is : " << m << std::endl;

    Fixed n(10.11f);
    std::cout << "n : " << n << std::endl;

	std::cout << "--n : " << --n << std::endl;
	std::cout << "n now is : " << n << std::endl;
	std::cout << "n-- : " << n-- << std::endl;
	std::cout << "n now is : " << n << std::endl;

/*                   Max and min tests                              */

	std::cout << std::endl;
    std::cout << "****** Max and min tests ******" << std::endl << std::endl;

    Fixed x(10.11f);
	std::cout << "x : " << x << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "max(x, b) : " << Fixed::max(x, b) << std::endl;
	std::cout << "min(x, b) : " << Fixed::min(x, b) << std::endl;

    const Fixed constH(7.35f);
    const Fixed constK(3.78f);
    std::cout << "Const H : " << constH << std::endl;
    std::cout << "Const K : " << constK << std::endl;
    std::cout << "min const (const H, const K) : " << Fixed::min(constH, constK) << std::endl;
    std::cout << "max const (const H, const K) : " << Fixed::max(constH, constK) << std::endl;

	return (0);
}
