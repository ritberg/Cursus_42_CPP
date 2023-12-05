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
    (void)rhs;
    return (*this);
}

/*           OUTPUT            */

void    ScalarConverter::outputChar(char c)
{
    std::cout << "Char conversion" << std::endl << std::endl;

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
    std::cout << "Int conversion" << std::endl << std::endl;

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

void    ScalarConverter::outputDouble(double d)
{
    std::cout << "Double conversion" << std::endl << std::endl;

    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void    ScalarConverter::outputFloat(float f)
{
    std::cout << "Float conversion" << std::endl << std::endl;

    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void outputStr(const std::string &literal)
{    
    std::cout << "Weird str conversion" << std::endl << std::endl;

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;

}

/*           IS SMTH           */

bool    isInt(const std::string & literal)
{
    for (int i = 0; i < literal.size(); i++)
    {
        if (!std::isdigit(literal[i]))
            return (false); 
    }
    return (true);
}

bool    isDouble(const std::string & literal)
{
    std::size_t found = literal.find(".");
    if (found != std::string::npos)
    {
        std::size_t found2 = literal.find("f");
        if (found2 == std::string::npos)
            return (true);
    }
    return (false);
}

bool    isFloat(const std::string & literal)
{
    std::size_t found = literal.find("f");
    if (found != std::string::npos && found != literal.size() - 1)
        throw ScalarConverter::InvalidInput();
    if (found != std::string::npos)
    {
        int count = 0;
        for (int i = 0;  i < literal.size(); i++)
        {
            if (literal[i] == '.')
                count++;
        }
        std::size_t found2 = literal.find(".");
        if (found2 != std::string::npos && count == 1)
           return (true);
    }
    return (false);
}

bool	isWeirdStr(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf"
			|| literal == "-inff" || literal =="+inff"
			||  literal == "-inf" || literal == "+inf");
}

/*           CONVERT METHOD           */

void    ScalarConverter::convert(const std::string & literal)
{
    try
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
        else if (isWeirdStr(literal))
            outputStr(literal);
        else if (isFloat(literal))
        {
            float f = std::atof(literal.c_str());
            outputFloat(f);
        }
        else if (isDouble(literal))
        {
            char* end;
            double d = std::strtod(literal.c_str(), &end);
            if (*end == 0)
                outputDouble(d);
        }
        else if (isInt(literal))
        {
            int i = std::atoi(literal.c_str());
            outputInt(i);
        }
        else
            throw ScalarConverter::InvalidInput();
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Conversion error: Out of range" << std::endl;
    }
    catch (const ScalarConverter::InvalidInput& e)
    {
        std::cerr << e.what() << std::endl;
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