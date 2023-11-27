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

int main()
{
    std::cout <<  std::endl << "----------------- LOW AT THE CONSTRUCTION --------------------" << std::endl << std::endl;
    try
    {
        int grade = 151;
        Bureaucrat a("Vasya", grade);
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << "after decrementGrade(): " << a << std::endl;
        a.incrementGrade();
        std::cout << "after incrementGrade(): " << a << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;;
    }
    catch(const Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout << std::endl << "----------------- HEIGH AT THE CONSTRUCTION --------------------" << std::endl << std::endl;

    try
    {
        int grade = -1;
        Bureaucrat a("Qqch", grade);
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << "after decrementGrade(): " << a << std::endl;
        a.incrementGrade();
        std::cout << "after incrementGrade(): " << a << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout << std::endl << "----------------- OK --------------------" << std::endl << std::endl;

    try
    {
        int grade = 14;
        Bureaucrat a("Petya", grade);
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << "after decrementGrade(): " << a << std::endl;
        a.incrementGrade();
        std::cout << "after incrementGrade(): " << a << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }
  
   std::cout << std::endl << "----------------- IMPOSSIBLE TO DECREMENT --------------------" << std::endl << std::endl;

   try
    {
        Bureaucrat a; //by default grade = 150
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << "after decrementGrade(): " << a << std::endl;
        a.incrementGrade();
        std::cout << "after incrementGrade(): " << a << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout << std::endl << "----------------- IMPOSSIBLE TO INCREMENT --------------------" << std::endl << std::endl;

    Bureaucrat b("Dog1", 1);
    Bureaucrat d("Dog2", 1);

    try
    {
        std::cout << "b is: " << b << std::endl;
        b.incrementGrade(); // stops here because grade cannot be 0
        std::cout << "b after incrementGrade(): " << b << std::endl;
        std::cout << "d is: " << d << std::endl;
        d.decrementGrade();
        std::cout << "d after decrementGrade(): " << d << std::endl;
        d.incrementGrade();
        std::cout << "d after incrementGrade(): " << d << std::endl;

    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    std::cout << std::endl << "----------------- = OPERATOR --------------------" << std::endl << std::endl;

    Bureaucrat c("Cat", 120);
    Bureaucrat u;
    c = u;

    std::cout << std::endl << "----------------- << OPERATOR --------------------" << std::endl << std::endl;

    std::cout << c << std::endl;

    std::cout << std::endl << "----------------" << std::endl << std::endl;

    return (0);
}