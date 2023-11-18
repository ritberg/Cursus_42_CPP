/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/14 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RESET	"\e[0m"
# define GREEN "\033[32m"

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain (std::string idea);
        Brain(Brain const & src);
        ~Brain(void);
        Brain&  operator=(Brain const & rhs);

        std::string* getIdeas();
        void    setIdeas(std::string ideas, int i);
};

#endif