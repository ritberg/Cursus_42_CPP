/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void printElems(int i)
{
    std::cout << i << std::endl;
}

int main()
{
    std::cout << std::endl << YELLOW "************** SUBJECT TEST *****************" RESET <<  std::endl << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
  
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl << YELLOW "************** OTHER TESTS *****************" RESET <<  std::endl << std::endl;

    std::cout << std::endl << GREEN "---print array---" RESET <<  std::endl << std::endl;

    std::for_each(sp.getArr().begin(), sp.getArr().end(), printElems);

    std::cout << std::endl << RED "---add one more int---" RESET <<  std::endl << std::endl;

    try
    {
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << RED "---only one n in the array---" RESET <<  std::endl << std::endl;

    Span sp1 = Span(1);
    try
    {
        std::cout << sp1.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << RED "---empty array---" RESET <<  std::endl << std::endl;

    Span sp2 = Span(0);
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << GREEN "---array with 10 000 elements---" RESET <<  std::endl << std::endl;

    Span bigSp(10000);

    std::vector<int> numbers;
    for (int i = 1; i <= 10000; ++i)
        numbers.push_back(i);

    bigSp.addRange(numbers.begin(), numbers.end());

    std::cout << bigSp.shortestSpan() << std::endl;
    std::cout << bigSp.longestSpan() << std::endl;

    
    return (0);
}