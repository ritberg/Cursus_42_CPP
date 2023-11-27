/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

# define RESET	"\e[0m"
# define GREEN "\033[32m"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm&  operator=(RobotomyRequestForm const & rhs);

        void    execute(Bureaucrat const & executor) const;
};

std::ostream&   operator<<(std::ostream& o, const RobotomyRequestForm& i);

#endif