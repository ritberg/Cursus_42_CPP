/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <limits>
# include <vector>
# include <list>
# include <map>
# include <string>
# include <algorithm>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define RED "\033[91m"
# define YELLOW "\033[33m"
# define BLUE   "\033[96m"

template <typename T>
void print(const T &element);

template<typename T>
typename T::iterator easyfind(T & elems, int x)
{
     typename T::iterator it = std::find(elems.begin(), elems.end(), x);
    if (it != elems.end())
    {
        print(*it);
        return (it);
    }
    else
        throw std::range_error("❗️Element is out of range");
}

// Specialization for printing elements of a std::list
template<>
void print(const int& element) {
    std::cout << "Element found in list: " << element << std::endl << std::endl;
}

// Regular print function for other containers
template<typename T>
void print(const T& element) {
    std::cout << element << std::endl;
}

#endif