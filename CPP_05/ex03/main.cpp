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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void runBureaucratWithGrade(int grade)
{
    try
    {
        Bureaucrat b("Petya", grade);

        ShrubberyCreationForm shr("home");
        RobotomyRequestForm rob("smth");
        PresidentialPardonForm pre("hi");

        std::cout <<  std::endl << YELLOW "-----Bureaucrat and shr form----" RESET << std::endl << std::endl;

        b.signForm(shr);
        b.executeForm(shr);

        std::cout <<  std::endl << GREEN "-----Bureaucrat and rob form----" RESET << std::endl << std::endl;

        b.signForm(rob);
        b.executeForm(rob);

        std::cout <<  std::endl << BLUE "-----Bureaucrat and pre form----" RESET << std::endl << std::endl;

        b.signForm(pre);
        b.executeForm(pre);

        std::cout <<  std::endl << "---------" << std::endl << std::endl;

    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;;
    }
}

int main()
{
    // std::cout <<  std::endl << "**************************************" << std::endl;
    // std::cout << "************ GRADE = 149 *************" << std::endl;
    // std::cout << "**************************************" << std::endl << std::endl;

    // runBureaucratWithGrade(149); // nothing is signed nor executed

    // std::cout <<  std::endl << "**************************************" << std::endl;
    // std::cout << "************ GRADE = 100 *************" << std::endl;
    // std::cout << "**************************************" << std::endl << std::endl;

    // runBureaucratWithGrade(100); // only SchrubberyCreation is signed and executed

    // std::cout <<  std::endl << "*************************************" << std::endl;
    // std::cout << "************ GRADE = 71 *************" << std::endl;
    // std::cout << "*************************************" << std::endl << std::endl;

    // runBureaucratWithGrade(71); // SchrubberyCreation is signed and executed; Robotomy is signed. That's it

    // std::cout <<  std::endl << "************************************" << std::endl;
    // std::cout << "************ GRADE = 6 *************" << std::endl;
    // std::cout << "************************************" << std::endl << std::endl;

    // runBureaucratWithGrade(6); // all ok but PresidentialPardon not executed

    // std::cout <<  std::endl << "************************************" << std::endl;
    // std::cout << "************ GRADE = 1 *************" << std::endl;
    // std::cout << "************************************" << std::endl << std::endl;

    // runBureaucratWithGrade(1); // all ok
    
    // std::cout <<  std::endl << "**************************************" << std::endl;
    // std::cout << "************ GRADE = 156 *************" << std::endl;
    // std::cout << "**************************************" << std::endl << std::endl;

    // runBureaucratWithGrade(156); // error from the beginning in Bureaucrat


    
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    delete rrf;

    std::cout << std::endl << "-------------------OK------------------" << std::endl << std::endl;

    Intern	intern = Intern();
	Bureaucrat b("Petya", 1);
	AForm*	f;
	try
	{
		f = intern.makeForm("presidential request", "Vasya");
        if (f != NULL)
		{
            b.signForm(*f);
		    b.executeForm(*f);
		    delete f;
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << std::endl << "-------------------NOT OK------------------" << std::endl << std::endl;

    Intern	intern1 = Intern();
	Bureaucrat b1("Petya", 1);
	AForm*	f1;
	try
	{
		f1 = intern1.makeForm("unknown request", "Vasya");
        if (f1 != NULL)
        {
            b1.signForm(*f1);
            b1.executeForm(*f1);
            delete f1;
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return (0);
}