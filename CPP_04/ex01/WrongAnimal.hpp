/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal {
 
    public:
        WrongAnimal(void);
        WrongAnimal(std::string AnimalType);
        WrongAnimal(WrongAnimal const & src);
        virtual ~WrongAnimal(void);

        WrongAnimal&  operator=(WrongAnimal const & rhs);

        void    makeSound() const;

        std::string     getType() const;

    protected:
        std::string type;

};

#endif