/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void inside_check(std::ifstream   &ifs)
{
    std::string line;
    // while (std::getline(ifs, line))

}

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw std::invalid_argument("Usage: ./btc <filename>");

        BitcoinExchange btc;
        btc.checkInput(argv[1]);
        btc.loadDatabase(argv[1]);
        btc.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}