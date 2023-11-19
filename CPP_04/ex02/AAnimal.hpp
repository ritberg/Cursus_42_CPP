/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>

class AAnimal {
 
    public:
        AAnimal(void);
        AAnimal(std::string AnimalType);
        AAnimal(AAnimal const & src);
        virtual ~AAnimal(void);

        AAnimal&  operator=(AAnimal const & rhs);

        virtual void    makeSound() const = 0; //pure virtual function

        std::string     getType() const;

    protected:
        std::string type;

};

#endif