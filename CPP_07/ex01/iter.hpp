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

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

template <typename T>
T iter(T & a, T & b) //
{
    for (int i = 0; i < b; i++)
        std::cout << a(i) << std::endl;
    return (a); //?
}

template <typename T>
T (*addPointer)(T, T) = &iter;

template<typename T>
void applyIter(T & adr, T & len, T (*Function)(T, T)) //
{
    Function(adr, len);
}

#endif