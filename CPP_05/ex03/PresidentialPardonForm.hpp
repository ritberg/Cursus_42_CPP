/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/25 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"

# define RESET	"\e[0m"
# define BLUE   "\033[96m"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm&  operator=(PresidentialPardonForm const & rhs);
        
        void    execute(Bureaucrat const & executor) const;
};

std::ostream&   operator<<(std::ostream& o, const PresidentialPardonForm& i);

#endif