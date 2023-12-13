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

class Span
{
    public:
        Span(void) {}
        Span(unsigned int N) : _n(N) {}
        ~Span(void) {}

        Span&  operator=(Span const & rhs);

        Span& addNumber(Span & old, int new_i);

        // shortestSpan()
        // longestSpan()

    private:
        unsigned int _n;

};

#endif