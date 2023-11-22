/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int garde);
        Bureaucrat(Bureaucrat const & src);
        virtual ~Bureaucrat(void);

        Bureaucrat&  operator=(Bureaucrat const & rhs);

        std::string getName() const;
        int         getGrade() const;

        void    decrementGrade();
        void    incrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("❗️ Error: the grade is too high");
                };
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("❗️ Error: the grade is too low");
                };
        };
};

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& i);

#endif