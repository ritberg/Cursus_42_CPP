/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

# define RESET	"\e[0m"
# define YELLOW "\033[33m"

class Cat : public Animal {
 
    public:
        Cat(void);
        Cat(std::string CatType);
        Cat(Cat const & src);
        ~Cat(void);

        Cat&    operator=(Cat const & rhs);

        void    makeSound() const;

        Brain*  getBrain(void) const;

    private:
        Brain*  _brain;

};

#endif