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
    std::cout <<BLUE "🔵 Default constructor for Pardon called" RESET << std::endl;
    this->_target = "default";
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon", 25, 5)
{
    std::cout << BLUE "🔵 Constructor for Pardon called with the following target = "
                    << target << RESET << std::endl;
    this->_target = target;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
    std::cout << BLUE "🔵 Copy constructor for Pardon called" RESET << std::endl;
    *this = src;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << BLUE "🔵 Destructor for Pardon called" RESET << std::endl;
    return;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    std::cout << BLUE "🔵 Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const PresidentialPardonForm & i)
{
    o << BLUE "🔵 " << i.getName() << " is a form with a gradeSign = " << i.getGradeSign()
        << " and a gradeExec = " << i.getGradeExec() << RESET;
    return (o);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getBool() == false)
        throw AForm::FormIsNotSigned();
    if (executor.getGrade() > 5)
        throw AForm::GradeTooLowException();
    std::cout << BLUE "🔵 "  << this->_target << " has been pardoned by Zaphod Beeblebrox" RESET << std::endl;
   
    return;
}