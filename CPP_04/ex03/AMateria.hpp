/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
class AMateria
{
    protected:
        ///
    public:
        AMateria(std::string const & type);
        ///
        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0;

        virtual void use(ICharacter& target);
};

#endif