/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
 
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float nf);
        Fixed(Fixed const & src);
        ~Fixed(void);

        Fixed&  operator=(Fixed const & rhs);

        Fixed   operator+(Fixed const & rhs) const;
        Fixed   operator-(Fixed const & rhs) const;
        Fixed   operator*(Fixed const & rhs) const;
        Fixed   operator/(Fixed const & rhs) const;

        bool    operator>(Fixed const & rhs) const;
        bool    operator<(Fixed const & rhs) const;
        bool    operator>=(Fixed const & rhs) const;
        bool    operator<=(Fixed const & rhs) const;
        bool    operator==(Fixed const & rhs) const;
        bool    operator!=(Fixed const & rhs) const;

        Fixed&  operator++(void);
        Fixed&  operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);

        static Fixed& min(Fixed& lhs, Fixed& rhs);
        static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
        static Fixed& max(Fixed& lhs, Fixed& rhs);
        static Fixed const & max(Fixed const & lhs, Fixed const & rhs);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

    private:
        int                 _value;
        static const int    _fract;
};

std::ostream&   operator<<(std::ostream& o, Fixed const & i);

#endif