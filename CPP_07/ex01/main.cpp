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

#include "iter.hpp"

int main()
{
    std::cout << std::endl << BLUE "*********** int tab[] = {0, 1, 2, 3, 4} ****************" RESET << std::endl;

    int tab[] = {0, 1, 2, 3, 4};
    std::cout << std::endl <<  BLUE "3 ways to call iter():" RESET << std::endl;

    std::cout << std::endl << BLUE <<
            "iter(tab, 5, &iterPrint<int>) - iter function is in the current scope or namespace where it is called" RESET << std::endl;
    iter(tab, 5, &iterPrint<int>);

    std::cout << std::endl << BLUE <<
            "::iter(tab, 5, &iterPrint<int>) - possibility to specify the scope or namespace explicitly" RESET << std::endl;
    ::iter(tab, 5, &iterPrint<int>);

    std::cout << std::endl << BLUE "::iterPrint(tab, 5)" RESET << std::endl;
    ::iterPrint(tab, 5);


    std::cout << std::endl << YELLOW "*********** std::string tab2[] = {\"Hello\", \"World\", \"!\"} ****************" RESET << std::endl;

    std::string tab2[] = {"Hello", "World", "!"};
    ::iter(tab2, 3, &iterPrint<std::string>);


    std::cout << std::endl << GREEN "*********** double tab3[] = {0.04, 1.15, 2.27, 3.38, 4.42} ****************" RESET << std::endl;

    double tab3[] = {0.04, 1.15, 2.27, 3.38, 4.42};
    ::iter(tab3, 5, &iterPrint<double>);


    std::cout << std::endl << VIOLET "*********** float tab4[] = {0.04f, 1.15f, 2.27f, 3.38f, 4.42f} ****************" RESET << std::endl;
    float tab4[] = {0.04f, 1.15f, 2.27f, 3.38f, 4.42f};
    ::iter(tab4, 5, &iterPrint<float>);

    std::cout << std::endl << RED "*********** Empty array ****************" RESET << std::endl;
    int tab5[] = {};
    ::iter(tab5, 0, &iterPrint<int>);
    std::cout << std::endl;

    return (0);
}