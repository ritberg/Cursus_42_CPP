/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_inventory[4];
        int _count;

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const & src);
        virtual ~MateriaSource(void);
        
        MateriaSource & operator=(MateriaSource const & rhs);

        virtual void learnMateria(AMateria* materia);
        virtual AMateria* createMateria(std::string const & type);
};

#endif