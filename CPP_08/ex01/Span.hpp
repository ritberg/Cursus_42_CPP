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
# include <fstream>

# define RESET	"\e[0m"
# define GREEN "\033[32m"
# define RED "\033[91m"
# define YELLOW "\033[33m"
# define BLUE   "\033[96m"
# define VIOLET	"\033[35m"

class Span
{
    private:
        std::vector<int> _arr;
        unsigned int _maxN;

    public:
        Span(void);
        Span(unsigned int N);
        ~Span(void);

        Span&  operator=(Span const & rhs);

        void addNumber(unsigned int newN);
        std::vector<int>& getArr(void);

        int shortestSpan(void);
        int longestSpan(void);

         void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

};

std::ostream &	operator<<(std::ostream &out, Span & obj);

#endif