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
class Fixed {
 
    public:
        Fixed(void);
        Fixed(Fixed const & src);
        ~Fixed(void);

        Fixed&  operator=(Fixed const & rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 _value;
        static const int    _fract;
};

std::ostream&   operator<<(std::ostream& o, Fixed const & i);

#endif