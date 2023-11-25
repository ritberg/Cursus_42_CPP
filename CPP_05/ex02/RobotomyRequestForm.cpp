/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
    std::cout << GREEN "🟢 Default constructor called for " << this->getName() << " with gradeSign = "
        << this->getGradeSign() << " and gradeExec = " << this->getGradeExec() << RESET << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int n, int nb) : AForm(name, n, nb)
{
    std::cout << GREEN "🟢 Str constructor for " << name << " called with gradeSign = " << n
        << " and gradeExec = " << nb << RESET << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
    std::cout << GREEN "🟢 Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << GREEN "🟢 Destructor called" RESET << std::endl;
    return;
}