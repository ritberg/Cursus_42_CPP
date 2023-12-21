/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange&  BitcoinExchange::operator=(BitcoinExchange const & other)
{
    if (this != &other)
    {
        this->_rates = other._rates;
    }
    return (*this);
}

void BitcoinExchange::checkInput(const std::string& input) const
{
    try
    {
        std::ifstream ifs;

        if (input.empty())
            throw std::invalid_argument("Error: empty input.");
        if (!ifs.is_open() || ifs.fail())
            throw std::runtime_error("Error: no such file or permission denied.");
        if (ifs.peek() == EOF)
            throw std::runtime_error("Error: empty file.");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void BitcoinExchange::loadDatabase(const std::string& file)
{

    std::ifstream ifs(file);
    std::string line;
    while (std::getline(ifs, line))
    {
        std::string date;
        double rate;
        std::istringstream iss(line);

        if (!(iss >> date >> rate))
            throw std::runtime_error("Error: bad input format in database file.");

        _rates[date] = rate;
    }

    ifs.close();

}