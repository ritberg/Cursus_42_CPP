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
	Fixed 			a;
	Fixed const		b(Fixed(5.05f) * Fixed(2));
	// Fixed const b(Fixed(5.05f) / Fixed(2));
	// Fixed const b(Fixed(5.05f) + Fixed(2));
	// Fixed const b(Fixed(5.05f) - Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	// Fixed x(10.11f);
	// std::cout << "x :" << x << std::endl;
	// std::cout << "b :" << b << std::endl;
	// std::cout << Fixed::max(x, b) << std::endl;
	// std::cout << Fixed::min(x, b) << std::endl;

	return (0);
}
