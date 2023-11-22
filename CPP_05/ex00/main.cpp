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
    std::cout <<  std::endl << "----------------- HIGH --------------------" << std::endl << std::endl;
    try
    {
        int grade = 151;
        Bureaucrat a("Vasya", grade);
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

    std::cout << std::endl << "----------------- LOW --------------------" << std::endl << std::endl;

    try
    {
        int grade = -1;
        Bureaucrat a;
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

    std::cout << std::endl << "----------------- INCR/DECR --------------------" << std::endl << std::endl;

    Bureaucrat b("Dog", 1);
    Bureaucrat d("Dog", 1);

    try
    {
        std::cout << "b is: " << b << std::endl;
        b.incrementGrade();
        std::cout << "b after incrementGrade(): " << b << std::endl;
        std::cout << "d is: " << d << std::endl;
        d.decrementGrade();
        std::cout << "d after decrementGrade(): " << d << std::endl;
        d.incrementGrade();
        std::cout << "d after incrementGrade(): " << d << std::endl;

        if (b.getGrade() < 1 || d.getGrade() < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (b.getGrade() > 150 || d.getGrade() > 150)
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

    std::cout << std::endl << "----------------- = OPERATOR --------------------" << std::endl << std::endl;

    Bureaucrat c("Cat", 120);
    Bureaucrat u;
    c = u;

    return (0);
}