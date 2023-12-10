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

#include "Array.hpp"

int main()
{
    std::cout << std::endl << BLUE "----- Array<> arr(10) " RESET << std::endl;

    Array<> arr(10);
    std::cout << BLUE << arr << RESET << std::endl;

    std::cout << std::endl << BLUE "----- Array<> arrNoParams1 " RESET << std::endl;

    Array<> arrNoParams1;
    std::cout << BLUE << arrNoParams1 << RESET << std::endl;

    std::cout << std::endl << YELLOW "----- Array<float> arrNoParams2 " RESET << std::endl;

    Array<float> arrNoParams2;
    std::cout << YELLOW << arrNoParams2 << RESET << std::endl;

    std::cout << std::endl << YELLOW "----- Array<double> arrDbl(5) " RESET << std::endl;

    Array<double> arrDbl(5);
    arrDbl[0] = 1.234567;
    arrDbl[1] = 2.345678;
    arrDbl[2] = 3.456789;
    arrDbl[3] = 4.567890;
    arrDbl[4] = 5.678901;
    std::cout << YELLOW << arrDbl << RESET << std::endl;

    std::cout << std::endl << GREEN "----- Array<int> arrInt(20) " RESET << std::endl;

    Array<int> arrInt(20);
    std::cout << GREEN << arrInt << RESET << std::endl;

    std::cout << std::endl << GREEN "----- Array<std::string> arrStr(2), arrStr[0] = \"42\", arrStr[1] = \"Lausanne\" " RESET << std::endl;

    Array<std::string> arrStr(2);
    arrStr[0] = "42";
    arrStr[1] = "Lausanne";
    std::cout << GREEN << arrStr << RESET << std::endl;

    std::cout << std::endl << RED "----- Out of array - arrStr[2] = \"à Renens\" " RESET << std::endl;
    try
    {
        arrStr[2] = "à Renens";
        std::cout << RED << arrStr << RESET << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << RED "❗️Error: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << RED "----- Out of array - Array<int> arrInteger(3), arrInteger[4] " RESET << std::endl;
    Array<int> arrInteger(3);

    arrInteger[0] = 10;
    arrInteger[1] = 20;
    arrInteger[2] = 30;
    try
    {
        std::cout << RED << arrInteger[4] << RESET << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << RED "❗️Error: " << e.what() << RESET << std::endl;
    }    


    std::cout << std::endl << "   *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << std::endl;
    std::cout << "  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << std::endl;
    std::cout << "   *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << std::endl;


    std::cout << std::endl << VIOLET "----- int* arrayInt = new int[20] " RESET << std::endl;

    int* arrayInt = new int[20];
    std::cout << VIOLET << arrInt << RESET << std::endl;
    delete [] arrayInt;

    std::cout << std::endl << GREY "----- int* a = new int() " RESET << std::endl;

    int* a = new int();
    std::cout << GREY << *a << RESET << std::endl;
    delete a;


    std::cout << std::endl;

    return (0);
}