/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
    std::cout << BLUE "🔵 Default constructor called for " << this->getName() << " with gradeSign = "
        << this->getGradeSign() << " and gradeExec = " << this->getGradeExec() << RESET << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int n, int nb) : AForm(name, n, nb)
{
    std::cout << BLUE "🔵 Str constructor for " << name << " called with gradeSign = " << n
        << " and gradeExec = " << nb << RESET << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
    std::cout << BLUE "🔵 Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << BLUE "🔵 Destructor called" RESET << std::endl;
    return;
}