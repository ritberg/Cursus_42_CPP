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
    if (argc == 2)
    {
        std::ifstream   ifs;
        if (std::string(argv[1]).empty()) /* return 1 if there are no strings */
            return (1); //throw exception
        
        ifs.open(argv[1], std::ifstream::in);
        if ((!ifs.is_open()) || ifs.fail()) /* return 1 if no file or cannot open */
        {
            std::cerr << "Error: no such file or permission denied." << std::endl; //throw exception
            return (1);
        }
        if (ifs.peek() == EOF) /* return 1 if empty file (inside) */
        {
            std::cerr << "Error: empty file." << std::endl; //throw exception
            return (1);
        }
        inside_check(ifs);
    }
    else
        std::cerr << "Usage: ./btc <filename>" << std::endl; //throw exception
    return (0);
}