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
# include <vector>

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

        void shortestSpan();
        // Comparison function for min_element and max_element
        template <typename T>
        struct Less
        {
            bool operator()(const T& a, const T& b) const { return a < b; };
        };
        // longestSpan()

};

std::ostream &	operator<<(std::ostream &out, Span & obj);

#endif