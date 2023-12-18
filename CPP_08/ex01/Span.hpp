/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <algorithm>
# include <limits>
# include <vector>
# include <list>
# include <fstream>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define RED "\033[91m"
# define YELLOW "\033[33m"
# define BLUE   "\033[96m"

class Span
{
    private:
        std::vector<int> _arr;
        unsigned int _maxN;

    public:
        Span(void);
        Span(unsigned int N);
        Span(Span const & src);
        ~Span(void);

        Span&  operator=(Span const & rhs);

        void addNumber(unsigned int newN);
        std::vector<int> const & getArr(void) const;

        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;

        /*
        not & begin and &end - it's more common to pass iterators by value, they are usually small objects

        addRange allows working with different container types that have iterators
            (more precisely, iterator interface, i.e., begin() and end() functions)
        */
        template <typename T>
        void addRange(typename T::const_iterator begin, typename T::const_iterator end)
        {
            unsigned int rangeSize = std::distance(begin, end);

            if (rangeSize > (this->_maxN - this->_arr.size()))
                throw std::out_of_range("❗️Error: adding the range would exceed the maximum capacity");
            else
                this->_arr.insert(this->_arr.end(), begin, end);
        } 
};

/*
The same as addRange - suitable for multiple containers
As the getArr member function returns a reference
    to a container type that provides begin() and end()
    member functions, I can use this operator with various
    container types, such as std::vector, std::list, etc.
*/
std::ostream &	operator<<(std::ostream &out, Span & obj);

#endif