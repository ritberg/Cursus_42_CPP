/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    std::cout << YELLOW "🟡 Default constructor called for " << this->getName() << " with gradeSign = "
        << this->getGradeSign() << " and gradeExec = " << this->getGradeExec() << RESET << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int n, int nb) : AForm(name, n, nb)
{
    std::cout << YELLOW "🟡 Str constructor for " << name << " called with gradeSign = " << n
        << " and gradeExec = " << nb << RESET << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
    std::cout << YELLOW "🟡 Copy constructor called" RESET << std::endl;
    *this = src;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << YELLOW "🟡 Destructor called" RESET << std::endl;
    return;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    std::cout << YELLOW "🟡 Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        // this->getBool() = rhs.getBool();
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const ShrubberyCreationForm & i)
{
    o << YELLOW "🟡 " << i.getName() << " is a form with a gradeSign = " << i.getGradeSign()
        << " and a gradeExec = " << i.getGradeExec() << RESET;
    return (o);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getBool() == true && executor.getGrade() <= this->getGradeExec())
    {
        std::string     ofsFileName = executor.getName() + "_shrubbery"; 
        std::ofstream   ofs(ofsFileName);
        ofs << "ASCII tree" << std::endl;
    }
    return;
}