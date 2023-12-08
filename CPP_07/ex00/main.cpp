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

#include "whatever.hpp"

int main(void)
{
    std::cout << std::endl << "************** SUBJECT TEST *****************" <<  std::endl << std::endl;

    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;



    std::cout << std::endl << GREEN "************** f1 = 0.42f, f2 = 42.0f *****************" RESET << std::endl << std::endl;

    float f1 = 0.42f;
    float f2 = 42.0f;

    std::cout << GREEN "f1 = " << f1 << ", f2 = " << f2 << RESET<< std::endl;
    std::cout << GREEN "min(f1, f2) = " << ::min(f1, f2) << RESET << std::endl;
    std::cout << GREEN "max(f1, f2) = " << ::max(f1, f2) << RESET << std::endl;
    ::swap(f1, f2);
    std::cout << GREEN "f1 after swap = " << f1 << ", f2 after swap = " << f2 << RESET<< std::endl;

    
    std::cout << std::endl << YELLOW "************** d1 = -345345634535435335345453454.045, d2 = 342343434.45 *****************" RESET << std::endl << std::endl;

    double d1 = -345345634535435335345453454.045;
    double d2 = 342343434.45;

    std::cout << YELLOW "d1 = " << d1 << ", d2 = " << d2 << RESET<< std::endl;
    std::cout << YELLOW "min(d1, d2) = " << ::min(d1, d2) << RESET << std::endl;
    std::cout << YELLOW "max(d1, d2) = " << ::max(d1, d2) << RESET << std::endl;
    ::swap(d1, d2);
    std::cout << YELLOW "d1 after swap = " << d1 << ", d2 after swap = " << d2 << RESET<< std::endl;

    return (0);
}