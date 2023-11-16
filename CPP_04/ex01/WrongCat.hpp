/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/12 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

# define RESET	"\e[0m"
# define YELLOW "\033[33m"

class WrongCat : public WrongAnimal {
 
    public:
        WrongCat(void);
        WrongCat(std::string CatType);
        WrongCat(WrongCat const & src);
        virtual ~WrongCat(void);

        WrongCat&    operator=(WrongCat const & rhs);

        void    makeSound() const;

};

// std::ostream& operator <<(std::ostream & o, Cat const & i);

#endif