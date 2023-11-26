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
    std::cout << GREEN "🟢 Default constructor for Robotomy called" RESET << std::endl;
    this->_target = "default";
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
    std::cout << GREEN "🟢 Constructor for Robotomy called with the following target = "
                    << target << RESET << std::endl;
    this->_target = target;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
    std::cout << GREEN "🟢 Copy constructor for Robotomy called" RESET << std::endl;
    *this = src;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << GREEN "🟢 Destructor for Robotomy called" RESET << std::endl;
    return;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    std::cout << GREEN "🟢 Copy assignment operator called" RESET << std::endl;
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& o, const RobotomyRequestForm & i)
{
    o << GREEN "🟢 " << i.getName() << " is a form with a gradeSign = " << i.getGradeSign()
        << " and a gradeExec = " << i.getGradeExec() << RESET;
    return (o);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getBool() == false)
        throw AForm::FormIsNotSigned();
    if (executor.getGrade() > 45)
        throw AForm::GradeTooLowException();
    std::cout << GREEN "🟢 * some drilling noises *" RESET << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    if (std::rand() % 2)
        std::cout << GREEN "🟢 " << this->_target << " was robotomized" RESET << std::endl;
    else
        std::cout << GREEN "🟢 " << this->_target << " was NOT robotomized this time" RESET << std::endl;
   
    return;
}