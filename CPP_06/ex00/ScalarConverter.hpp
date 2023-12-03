/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <cmath>
# include <limits>
# include <string>
# include <cstdlib>
# include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter(void);
    
    public:
        ScalarConverter&  operator=(ScalarConverter const & rhs);
        static void convert(const std::string & literal);

};

#endif