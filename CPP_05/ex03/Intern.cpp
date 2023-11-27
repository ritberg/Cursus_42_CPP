/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/26 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) 
{
    std::cout << RED "🔴 Default constructor for Intern called" RESET << std::endl;
    return;
}

Intern::Intern(Intern const & src)
{
    std::cout << RED "🔴 Copy constructor for Intern called" RESET << std::endl;
    *this = src;
    return;
}

Intern::~Intern(void)
{
    std::cout << RED "🔴 Destructor for Intern called" RESET << std::endl;
    return;
}

Intern&  Intern::operator=(Intern const & rhs)
{
    std::cout << RED "🔴 Copy assignment operator called" RESET << std::endl;
    (void)rhs;
    return (*this);
}

const char* Intern::ErrorMessage::what() const throw()
{
    return (RED "🔴 Intern doesn't know this form" RESET);
}

AForm*   Intern::makeForm(const std::string& formName, const std::string& target) const
{
    std::cout << RED "🔴 Intern creates " << formName << RESET << std::endl;

    AForm *form = NULL;
    std::string arr[3] = {"presidential request","robotomy request","shrubberry request"};
    int i = -1;
    while (arr[++i] != formName){}
    switch (i)
    {
        case 0:
            form = new PresidentialPardonForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            throw ErrorMessage();
            break;
    }
    return (form);
}

/* AN OTHER WAY TO DO IT */

// AForm*   Intern::makeForm(const std::string& formName, const std::string& target) const
// {
//      std::cout << RED "🔴 Intern creates " << formName << RESET << std::endl;

//     return 
//         (formName == "shrubberry request") ? new ShrubberyCreationForm(target) :
//         (formName == "robotomy request") ? new RobotomyRequestForm(target) :
//         (formName == "presidential request") ? new PresidentialPardonForm(target) :
//         (std::cout << RED "🔴 Intern doesn't know this form" RESET << std::endl, (AForm*)NULL);
// }
