/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/12 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void printElems(int i)
{
    std::cout << i << " ";
}

int main()
{
    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(6);

    std::cout << std::endl << YELLOW "------------ Print vector elements -----" RESET << std::endl;
    std::for_each(vect.begin(), vect.end(), printElems);

    try
    {
        std::cout << std::endl << std::endl << GREEN "------------ 1 and 6 are ok ------------" RESET << std::endl;
        std::vector<int>::iterator res = easyfind(vect, 1);
        std::vector<int>::iterator res1 = easyfind(vect, 6);
        std::cout << std::endl << RED "------------ 4 is not ok ---------------" RESET << std::endl;
        std::vector<int>::iterator res2 = easyfind(vect, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl << std::endl;
    }

    return (0);
}