/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("a bureaucrat by default"), _grade(150)
{
    std::cout << "⚪️ Default constructor for " << this->_name << " with the deafult grade = " << this->_grade << " called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "⚪️ Str + int constructor for " << name << " with a grade = " << grade << " called" << std::endl;
    if (this->_grade >= 151)
        throw Bureaucrat::GradeTooLowException();
    if (this->_grade <= 0)
        throw Bureaucrat::GradeTooHighException();
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "⚪️ Copy constructor called" << std::endl;
    *this = src;
    return;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "⚪️ Destructor called" << std::endl;
    return;
}

Bureaucrat&  Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "⚪️ Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_name = rhs.getName(); impossible because of const
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

std::string    Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void    Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

std::ostream&   operator<<(std::ostream& o, const Bureaucrat & i)
{
    o << "👋 " << i.getName() << " is a bureaucrat with a grade = " << i.getGrade();
    return (o);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("❗️ Error: the grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("❗️ Error: the grade is too low");
}