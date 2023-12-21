/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <map>
# include <stdexcept>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange(void);

        BitcoinExchange&  operator=(BitcoinExchange const & other);

        void checkInput(const std::string& input) const;
        void loadDatabase(const std::string& file);
        void processInput(const std::string& inputFile);

    private:
        std::map<std::string, double> _rates;
        double _findClosestExchangeRate(const std::string& date) const;
};

#endif