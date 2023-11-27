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

int main()
{
    std::cout << std::endl << GREEN "-------------------Subject test - robotomy request------------------" RESET << std::endl << std::endl;

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    delete rrf;

    std::cout << std::endl << BLUE "-------------------Presidential request - OK------------------" RESET << std::endl << std::endl;

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

    std::cout << std::endl << YELLOW "-------------------Shrubberry request - OK------------------" RESET << std::endl << std::endl;

    Intern	intern1 = Intern();
	Bureaucrat b1("Ivan", 1);
	AForm*	f1;
	try
	{
		f1 = intern1.makeForm("shrubberry request", "Oleg");
        if (f1 != NULL)
		{
            b1.signForm(*f);
		    b1.executeForm(*f);
		    delete f1;
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << std::endl << "-------------------Unknown request - NOT OK------------------" << std::endl << std::endl;

    Intern	intern2 = Intern();
	Bureaucrat b2("Anne", 1);
	AForm*	f2;
	try
	{
		f2 = intern2.makeForm("unknown request", "Intern inconnu");
        if (f2 != NULL)
        {
            b2.signForm(*f2);
            b2.executeForm(*f2);
            delete f2;
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
    std::cout <<std::endl << "-------" << std::endl << std::endl;

    return (0);
}