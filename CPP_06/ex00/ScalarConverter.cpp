/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) 
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter&  ScalarConverter::operator=(ScalarConverter const & rhs)
{
    return (*this);
}

void    ScalarConverter::outputChar(char c)
{
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void    ScalarConverter::outputInt(int i)
{
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void specialOutput(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}


void    ScalarConverter::convert(const std::string & literal)
{
    if (literal.empty())
        throw ScalarConverter::InvalidInput();
    else if (literal.size() == 1)
    {
        if (std::isdigit(literal[0]))
        {
            int i = std::atoi(literal.c_str());
            outputInt(i);
        }
        else
            outputChar(literal[0]);
    }
    else
    {
        if (literal == "nan" || literal == "nanf" || literal == "-inff" || literal =="+inff"
			||  literal == "-inf" || literal == "+inf")
            specialOutput(literal);
    }

}

const char *ScalarConverter::InvalidInput::what() const throw()
{
    return ("Invalid input");
}



/*  C++11 */
/*
void    ScalarConverter::convert(const std::string & literal)
{
    try
    {
        // Convert to char. If the character is printable (!= null), output it
        char charValue = static_cast<char>(std::stoi(literal)); // stoi, stod, stof are C++11 !
        if (isprint(charValue))
            std::cout << "char: '" << charValue << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        // Convert to int
        int intValue = static_cast<int>(std::stoi(literal));
        std::cout << "int: " << intValue << std::endl;

        // Convert to float
        float floatValue = static_cast<float>(std::stof(literal));
        // std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "float: " << floatValue << (floatValue == std::floor(floatValue) ? ".0f" : "f") << std::endl;

        // Convert to double
        double doubleValue = static_cast<double>(std::stod(literal));
        // std::cout << "double: " << doubleValue << std::endl;
        std::cout << "double: " << doubleValue << (doubleValue == std::floor(doubleValue) ? ".0" : "") << std::endl;

        
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Conversion error: Out of range" << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << literal + "f" << std::endl;
        std::cout << "double: " << literal << std::endl;

    }
}
*/