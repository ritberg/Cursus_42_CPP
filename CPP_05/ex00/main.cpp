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
    try
    {
        int grade = 101;
        Bureaucrat a("Vasya", grade);
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << "after decrementGrade(): " << a << std::endl;
        a.incrementGrade();
        std::cout << "after incrementGrade(): " << a << std::endl;

        if (grade < 1)
            throw Bureaucrat::GradeTooLowException();
        else if (grade > 100)
            throw Bureaucrat::GradeTooHighException();
    }
    catch(const Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;;
    }
    catch(const Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;;
    }

    return (0);
}