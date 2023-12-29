/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/26 22:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    *this = src;
}

PmergeMe::~PmergeMe(void)
{
}

void PmergeMe::checkInput(char* input) const
{
    for (size_t i = 0; i < strlen(input); ++i)
    {
        if (!isdigit(input[i]))
            throw std::invalid_argument("Error: not a positive integer");
    }
    if (atoi(input) < 0)
        throw std::invalid_argument("Error: atoi() failed");
}
