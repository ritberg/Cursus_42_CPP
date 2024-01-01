/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/26 22:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "test.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Error: please enter a positive integer sequence");

        PmergeMe sorter;
        for (int i = 1; i < argc; ++i)
        {
            sorter.checkInput(argv[i]);
            sorter.getVector().push_back(std::atoi(argv[i]));
        }
        sorter.displayResults();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}