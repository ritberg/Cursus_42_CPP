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
    std::cout << std::endl << "************** SUBJECT TEST *****************" <<  std::endl << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
  
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl << "************** OTHER TESTS *****************" <<  std::endl << std::endl;

    std::cout << std::endl << "---print array---" <<  std::endl << std::endl;

    std::for_each(sp.getArr().begin(), sp.getArr().end(), printElems);

    std::cout << std::endl << "---add one more int---" <<  std::endl << std::endl;

    try
    {
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}