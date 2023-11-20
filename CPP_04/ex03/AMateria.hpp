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
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        virtual ~AMateria(void);

        AMateria & operator=(AMateria const & rhs);
        
        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0;

        virtual void use(ICharacter& target);
};

#endif