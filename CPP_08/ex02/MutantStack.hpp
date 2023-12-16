/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <vector>
# include <list>
# include <stack>
# include <algorithm>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define RED "\033[91m"
# define YELLOW "\033[33m"
# define BLUE   "\033[96m"
# define VIOLET	"\033[35m"

template < typename T >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void) {}
        ~MutantStack(void) {}

        MutantStack&  operator=(MutantStack const & other) { return (*this); }

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() { return (std::stack<T>::c.begin()); }
        iterator end() { return std::stack<T>::c.end(); }

        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }

};

template < typename T >
std::ostream &	operator<<(std::ostream &out, MutantStack<T> & obj)
{
    out << BLUE "--Summary for the created stack--" RESET << std::endl;
    out << BLUE "Top: " << obj.top() << RESET << std::endl;
    out << BLUE "Size: " << obj.size() << RESET << std::endl;
    std::cout << BLUE "The stack contains:" << std::endl;
    while (!obj.empty())
    {
        std::cout << BLUE << obj.top() << RESET << std::endl;
        obj.pop();
    }
    return (out);
}


#endif