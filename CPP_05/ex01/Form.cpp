/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* 1 - all rights, 150 - no rights */
Form::Form(void) : _name("a form by default"), _formIsSigned(false), _gradeSign(1), _gradeExec(1)
{
    std::cout << VIOLET "🟣 Default constructor called for " << this->_name << " with gradeSign = "
        << this->_gradeSign << " and gradeExec = " << this->_gradeExec << RESET << std::endl;
    return;
}

Form::Form(std::string name, int n, int nb) : _name(name),  _formIsSigned(false), _gradeSign(n), _gradeExec(nb)
{
    std::cout << VIOLET "🟣 Constructor for " << name << " called with gradeSign = " << n
        << " and gradeExec = " << nb << RESET << std::endl;
    return;
}

Form::Form(Form const & src) : _name(src._name),  _formIsSigned(false), _gradeSign(1), _gradeExec(1)
{
    std::cout << VIOLET "🟣 Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

Form::~Form(void)
{
    std::cout << VIOLET "🟣 Destructor called" RESET << std::endl;
    return;
}

std::string Form::getName(void) const
{
    return (this->_name);
}

int Form::getGradeSign() const
{
    return (this->_gradeSign);
}

int Form::getGradeExec() const
{
    return (this->_gradeExec);
}

bool    Form::getBool() const
{
    return (this->_formIsSigned);
}

Form&  Form::operator=(Form const & rhs)
{
    std::cout << VIOLET "🟣 Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_formIsSigned = rhs._formIsSigned;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const Form & i)
{
    o << VIOLET "🟣 " << i.getName() << " is a form with a gradeSign = " << i.getGradeSign()
        << " and a gradeExec = " << i.getGradeExec() << RESET;
    return (o);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return (VIOLET "🟣❗️ Error: the grade is too high" RESET);
}

const char* Form::GradeTooLowException::what() const throw()
{
    return (VIOLET "🟣❗️ Error: the grade is too low" RESET);
}

bool    Form::beSigned(Bureaucrat & b)
{
    if (b.getGrade() > this->_gradeSign)
    {
        this->_formIsSigned = false;
        throw Form::GradeTooLowException();
    }
    this->_formIsSigned = true;
    return (this->_formIsSigned);
}

/* old */
// bool    Form::beSigned(Bureaucrat & b)
// {
//     if (b.getGrade() <= this->_gradeSign)
//     {
//         this->_formIsSigned = true;
//         return (this->_formIsSigned);
//     }
//     this->_formIsSigned = false;
//     return (this->_formIsSigned);
// }