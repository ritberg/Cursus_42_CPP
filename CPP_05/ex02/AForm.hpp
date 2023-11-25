/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <string>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include "Bureaucrat.hpp"

# define RESET	"\e[0m"
# define VIOLET	"\033[35m"

class Bureaucrat;
class AForm 
{
    private:
        const std::string   _name;
        bool                _formIsSigned;
        const int           _gradeSign;
        const int           _gradeExec;

    public:
        AForm(void);
        AForm(std::string name, int n, int nb);
        AForm(AForm const & src);
        virtual ~AForm(void);

        AForm&  operator=(AForm const & rhs);

        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getBool() const;

        bool        beSigned(Bureaucrat & b);

        virtual void    execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream& o, const AForm& i);

#endif