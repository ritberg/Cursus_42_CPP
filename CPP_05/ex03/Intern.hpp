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

# define RESET	"\e[0m"
# define RED "\033[91m"

class Intern
{
    public:
        Intern(void);
        Intern(Intern const & src);
        ~Intern(void);

        Intern&  operator=(Intern const & rhs);

        AForm*   makeForm(const std::string& formName, const std::string& target) const;
        
        class ErrorMessage : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

#endif