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

        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(const Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;;
    }
    catch(const Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;;
    }
    
    Bureaucrat b("Petya", 11);

    Form f("pdf", 4, 9);
    f.beSigned(b);
    std::cout << f << std::endl;

    return (0);
}