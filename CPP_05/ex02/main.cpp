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

int main()
{
    int grade = 2;
    Bureaucrat b("Petya", grade);

    int gradeSign = 5;
    int gradeExec = 9;

    ShrubberyCreationForm f("pdf", gradeSign, gradeExec);
    f.beSigned(b);
    b.signForm(f);
    f.execute(b);
    b.executeForm(f);
    std::cout << f << std::endl;
    

    return (0);
}