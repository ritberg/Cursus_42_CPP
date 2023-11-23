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
Form::Form(void) : _name("a bureaucrat by default"), _formIsSigned(false), _gradeSign(1), _gradeExec(1)
{
    std::cout << "🟣 Default constructor called" << std::endl;
    return;
}

Form::Form(std::string name, int n, int nb) : _name(name),  _formIsSigned(false), _gradeSign(n), _gradeExec(nb)
{
    std::cout << "🟣 Str constructor for " << name << " called" << std::endl;
    return;
}

Form::Form(Form const & src) : _name(src._name),  _formIsSigned(false), _gradeSign(1), _gradeExec(1)
{
    std::cout << "🟣 Copy constructor called" << std::endl;
    *this = src;
    return;
}

Form::~Form(void)
{
    std::cout << "🟣 Destructor called" << std::endl;
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

Form&  Form::operator=(Form const & rhs)
{
    std::cout << "🟣 Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_formIsSigned = rhs._formIsSigned;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const Form & i)
{
    o << "👋 " << i.getName() << " is a bureaucrat with a grade required to sign = " << i.getGradeSign()
        << " and a grade required to execute " << i.getGradeExec();
    return (o);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("❗️ Error: the grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("❗️ Error: the grade is too low");
}

void Form::beSigned(Bureaucrat & b)
{
    if (this->_gradeExec <= this->_gradeSign)
        this->_formIsSigned = true;
    this->_formIsSigned = false;
}
