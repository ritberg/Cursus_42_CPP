/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>
# include <string>
# include <iomanip>

# define RESET	"\e[0m"
# define BLUE   "\033[96m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define VIOLET	"\033[35m"
# define RED "\033[91m"
# define GREY "\033[30m"


template <typename T>
void iterPrint(T const & a)
{
    std::cout << a << std::endl;
}

/*
Iter() takes a pointer to an array of type T, the number of elements in that array and a function pointer.
*/
template<typename T>
void iter(T* adr, size_t len, void (*iter)(T const &))
{
    for (size_t i = 0; i < len; ++i)
        iterPrint(adr[i]);
}

#endif