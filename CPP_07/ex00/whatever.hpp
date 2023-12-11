/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>
# include <string>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define VIOLET	"\033[35m"

template<typename T>
void swap(T & x, T & y)
{
    T z;
    z = x;
    x = y;
    y = z;
}

template<typename T>
T const & min(T const& x, T const& y)
{
    return ((x < y) ? x : y);
}

template<typename T>
T const & max(T const& x, T const& y)
{
    return ((x > y) ? x : y);
}

#endif