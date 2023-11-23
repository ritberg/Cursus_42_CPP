/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form 
{
    private:
        const std::string   _name;
        bool                _formIsSigned;
        const int           _gradeSign;
        const int           _gradeExec;

    public:
        Form(void);
        Form(std::string name, int n, int nb);
        Form(Form const & src);
        virtual ~Form(void);

        Form&  operator=(Form const & rhs);

        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;

        void beSigned(Bureaucrat & b);

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

std::ostream&   operator<<(std::ostream& o, const Form& i);

#endif