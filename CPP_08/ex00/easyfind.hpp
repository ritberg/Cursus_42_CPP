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
# include <vector>
# include <string>
# include <algorithm>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define RED "\033[91m"
# define YELLOW "\033[33m"

template<typename T>
typename T::iterator easyfind(T & elems, int x)
{
    std::vector<int>::iterator it = std::find(elems.begin(), elems.end(), x);
    if (it != elems.end())
    {
        std::cout << *it << std::endl;
        return (it);
    }
    else
        throw std::range_error("❗️Element is out of range");
}

#endif