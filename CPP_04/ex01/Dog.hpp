/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

# define RESET	"\e[0m"
# define VIOLET	"\033[35m"

class Dog : public Animal {
 
    public:
        Dog(void);
        Dog(std::string DogType);
        Dog(Dog const & src);
        virtual ~Dog(void);

        Dog&    operator=(Dog const & rhs);

        void    makeSound() const;
        
        Brain*  getBrain(void) const;

    private:
        Brain*  _brain;

};

// std::ostream& operator <<(std::ostream & o, Dog const & i);

#endif