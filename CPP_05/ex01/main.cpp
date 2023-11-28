/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout <<  std::endl << "----------------- SMALLER THAN GRADE SIGN - SIGNED --------------------" << std::endl << std::endl;
    
    try
    {
        int grade = 2;
        Bureaucrat b("Petya", grade);

        int gradeSign = 5;
        int gradeExec = 9;

        Form f("pdf", gradeSign, gradeExec);
        // f.beSigned(b);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout <<  std::endl << "----------------- BIGGER THAN GRADE SIGN - DIDN'T SIGN --------------------" << std::endl << std::endl;
    
    try
    {
        int grade = 88;
        Bureaucrat b("Petya", grade);

        int gradeSign = 5;
        int gradeExec = 9;

        Form f("pdf", gradeSign, gradeExec);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout <<  std::endl << "----------------- TOO LOW AT THE CONSTRUCTION - ERROR --------------------" << std::endl << std::endl;
    
    try
    {
        int grade = 160;
        Bureaucrat b("Petya", grade);

        int gradeSign = 5;
        int gradeExec = 9;

        Form f("pdf", gradeSign, gradeExec);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout <<  std::endl << "----------------- TOO HIGH AT THE CONSTRUCTION - ERROR --------------------" << std::endl << std::endl;

    try
    {
        int grade = -2;
        Bureaucrat b("Petya", grade);

        int gradeSign = 5;
        int gradeExec = 9;

        Form f("pdf", gradeSign, gradeExec);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    return (0);
}