/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* 1 - all rights, 150 - no rights */
AForm::AForm(void) : _name("a form by default"), _formIsSigned(false), _gradeSign(1), _gradeExec(1)
{
    std::cout << VIOLET "🟣 Default constructor called for " << this->_name << " with gradeSign = "
        << this->_gradeSign << " and gradeExec = " << this->_gradeExec << RESET << std::endl;
    return;
}

AForm::AForm(std::string name, int n, int nb) : _name(name),  _formIsSigned(false), _gradeSign(n), _gradeExec(nb)
{
    std::cout << VIOLET "🟣 Constructor for " << name << " called with gradeSign = " << n
        << " and gradeExec = " << nb << RESET << std::endl;
    return;
}

AForm::AForm(AForm const & src) : _name(src._name),  _formIsSigned(false), _gradeSign(1), _gradeExec(1)
{
    std::cout << VIOLET "🟣 Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

AForm::~AForm(void)
{
    std::cout << VIOLET "🟣 Destructor called" RESET << std::endl;
    return;
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

int AForm::getGradeSign() const
{
    return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
    return (this->_gradeExec);
}

bool    AForm::getBool() const
{
    return (this->_formIsSigned);
}

AForm&  AForm::operator=(AForm const & rhs)
{
    std::cout << VIOLET "🟣 Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_formIsSigned = rhs._formIsSigned;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const AForm & i)
{
    o << VIOLET "🟣 " << i.getName() << " is a form with a gradeSign = " << i.getGradeSign()
        << " and a gradeExec = " << i.getGradeExec() << RESET;
    return (o);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return (VIOLET "🟣❗️ Error: the grade is too high" RESET);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return (VIOLET "🟣❗️ Error: the grade is too low" RESET);
}

const char* AForm::FormIsNotSigned::what() const throw()
{
    return (VIOLET "🟣❗️ Error: the form is not signed. Therefore, impossible to execute" RESET);
}

bool    AForm::beSigned(Bureaucrat & b)
{
    if (b.getGrade() > this->_gradeSign)
    {
        throw AForm::GradeTooLowException();
        this->_formIsSigned = false;
    }
    this->_formIsSigned = true;
    return (this->_formIsSigned);
}
