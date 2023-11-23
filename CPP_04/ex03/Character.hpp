/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/18 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_H
# define CHARACTER_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        
    public:
        Character(void);
        Character(std::string const & name);
        Character(Character const & src);
        virtual ~Character(void);
        
        Character & operator=(Character const & rhs);

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif