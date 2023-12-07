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
# include <cfloat>

# define RESET	"\e[0m"
# define RED "\033[91m"
# define BLUE   "\033[96m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define VIOLET	"\033[35m"

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter(void);
    
    public:
        ScalarConverter&  operator=(ScalarConverter const & rhs);
        static void convert(const std::string & literal);

        class InvalidInput : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &	operator<<(std::ostream &out, const ScalarConverter & obj);

#endif