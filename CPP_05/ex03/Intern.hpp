/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/26 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(Intern const & src);
        virtual ~Intern(void);

        Intern&  operator=(Intern const & rhs);

        AForm*   makeForm(std::string formName, std::string target);

};

std::ostream&   operator<<(std::ostream& o, const Intern& i);

#endif