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
        ifs.open (input, std::ifstream::in);
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
// {
//     std::ifstream ifs(file);
//     std::string line;
//     while (std::getline(ifs, line))
//     {
//         std::string date;
//         double value = 0;
//         std::istringstream iss(line);

//         if (std::getline(iss, date, ' ') && (iss >> value))
//             this->_rates[date] = value;

//         std::cout << "Debug: " << date << " | " << value << std::endl;
//     }
//     ifs.close();
// }

{
    std::ifstream ifs(file);
    std::string line;
    // Skip the first line
    std::getline(ifs, line);

    while (std::getline(ifs, line))
    {
        std::string date;
        double value = 0;
        std::istringstream iss(line);

        // Extract the first 10 characters as a std::string
        date = line.substr(0, 10);

        // Find the position of the first occurrence of " | "
        size_t pos = line.find(" | ");

        if (pos != std::string::npos)
        {
            // Extract characters after " | " as a double
            std::string valueStr = line.substr(pos + 3);
            std::istringstream valueIss(valueStr);
            if (valueIss >> value)
            {
                this->_rates[date] = value;
                std::cout << "Debug: " << date << " | " << value << std::endl;
            }
            else
                std::cerr << "Error converting value to double on line: " << line << std::endl;
        }
        else
        {
            // If " | " is not found, try extracting the value after a space
            this->_rates[date] = 0;
            std::cout << "Debug: " << date << " | " << value << std::endl;
        }
    }

    ifs.close();
}


void BitcoinExchange::processInput(const std::string& file)
{
    std::ifstream ifs(file);
    std::string line;
    std::getline(ifs, line);
    while (std::getline(ifs, line))
    {
        std::string date;
        double value;
        std::istringstream iss(line);

        iss >> date >> value;

        try
        {
            double exchangeRate = _findClosestExchangeRate("data.csv");
            double result = value * exchangeRate;

            // std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    ifs.close();
}

double BitcoinExchange::_findClosestExchangeRate(const std::string& date) const
{
    std::ifstream ifs(date);
    if (!ifs.is_open())
        throw std::runtime_error("Error: could not open exchange rate file.");

    std::map<std::string, double> exchangeRates;

    std::string line;
    std::string rateDate;
    double rate;
    std::getline(ifs, line);

    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);

        // Extract the first 10 characters as a std::string
        rateDate = line.substr(0, 10);

        // Find the position of the first occurrence of ","
        size_t pos = line.find(",");

        if (pos != std::string::npos)
        {
            // Extract characters after "," as a double
            std::string valueStr = line.substr(pos + 1);
            std::istringstream valueIss(valueStr);
            if (valueIss >> rate)
            {
                exchangeRates[rateDate] = rate;
                std::cout << "Debug: " << rateDate << "," << rate << std::endl;
            }
            else
                std::cerr << "Error converting value to double on line: " << line << std::endl;
        }
        else
        {
            // If "," is not found, try extracting the value after a space
            exchangeRates[rateDate] = 0;
            std::cout << "Debug: " << rateDate << "," << rate << std::endl;
        }
    }

    ifs.close();


    std::map<std::string, double>::const_iterator it = exchangeRates.begin();

    for (std::map<std::string, double>::iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) 
        std::cout << it->second << std::endl;


    return it->second;
}