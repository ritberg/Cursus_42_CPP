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

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    std::cout << YELLOW "🟡 Default constructor for Shrubbery called" RESET << std::endl;
    this->_target = "default";
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
    std::cout << YELLOW "🟡 Constructor for Shrubbery called with the following target = "
                        << target << RESET << std::endl;
    this->_target = target;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
    std::cout << YELLOW "🟡 Copy constructor for Shrubbery called" RESET << std::endl;
    *this = src;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << YELLOW "🟡 Destructor for Shrubbery called" RESET << std::endl;
    return;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    std::cout << YELLOW "🟡 Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const ShrubberyCreationForm & i)
{
    o << YELLOW "🟡 " << i.getName() << " is a form with a gradeSign = " << i.getGradeSign()
        << " and a gradeExec = " << i.getGradeExec() << RESET;
    return (o);
}

void    printTrees(std::ostream& ofs)
{
    ofs << "        *" << std::endl;
    ofs << "       / \\" << std::endl;
    ofs << "      / _ \\" << std::endl;
    ofs << "     /_/ \\_\\" << std::endl;
    ofs << "    /  \\_/  \\" << std::endl;
    ofs << "   /   / \\   \\" << std::endl;
    ofs << "  /___/___\\___\\" << std::endl;
    ofs << "      [___]" << std::endl;

    ofs << std::endl;

    ofs << "            @" << std::endl;
    ofs << "      @ @ @  @ @ @" << std::endl;
    ofs << "    @  @*/@ @ /__@" << std::endl;
    ofs << "    @ @ @ @*/ @/ * @ @" << std::endl;
    ofs << "   @*  *@| @ | * * @" << std::endl;
    ofs << "  @__*@ * |/ *** / @" << std::endl;
    ofs << "     __**|@| ** ||/__/@" << std::endl;
    ofs << "    /  * ***  / /__" << std::endl;
    ofs << "   @    *  */ /   @" << std::endl;
    ofs << "         |\" '|" << std::endl;
    ofs << "         |\"  |" << std::endl;
    ofs << "         |\"  |" << std::endl;
    ofs << "         |\"  |" << std::endl;
    ofs << "        ~|\"  |~" << std::endl;
    ofs << "    ~~~~       ~~~~" << std::endl;
    ofs << "  ~~               ~~~" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getBool() == false)
        throw AForm::FormIsNotSigned();
    if (executor.getGrade() > 137)
        throw AForm::GradeTooLowException();
    std::string     ofsFileName = this->_target + "_shrubbery"; 
    std::ofstream   ofs(ofsFileName);
    printTrees(ofs);
    ofs << std::endl;
    std::cout << YELLOW "🟡 Shrubbery trees were planted at the target " << this->_target << RESET << std::endl;
    return;
}
