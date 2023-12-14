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

    std::list<int> list;

    list.push_back(1);
    list.push_back(20);
    list.push_back(-3);
    list.push_back(66);

    std::cout << BLUE "------------ Print list elements -----" RESET << std::endl;
    std::for_each(list.begin(), list.end(), printElems);

    try
    {
        std::list<int>::iterator res3 = easyfind(list, 20);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl << std::endl;
    }


    // void printMapElem(const std::pair<const int, std::string>& element)
    // {
    //     std::cout << element.first << ": " << element.second << " ";
    // }
    
    // std::map<int, std::string> map;

    // map[1] = "one";
    // map[2] = "two";
    // map[3] = "three";

    // std::cout << std::endl << YELLOW "------------ Print map elements -----" RESET << std::endl;
    // std::for_each(map.begin(), map.end(), printMapElem);

    // try
    // {
    //     std::map<int, std::string>::iterator res4 = easyfind(map, 2);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl << std::endl;
    // }
    

    return (0);
}