/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:59 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/30 18:26:00 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl(void)
{
    return;
}

Harl::~Harl(void)
{
    return;
}

void    Harl::_debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my " <<
        "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    return;
}

void    Harl::_info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't " <<
        "put enough bacon in my burger! If you did, I wouldn’t be asking for more" << std::endl;
    return;
}

void    Harl::_warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming "<<
        "for years whereas you started working here since last month." << std::endl;
    return;
}

void    Harl::_error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (logLevels[i] == level)
        {
            switch (i)
            {
                case 0:
                    _debug();
                    break;
                case 1:
                    _info();
                    break;
                case 2:
                    _warning();
                    break;
                case 3:
                    _error();
                    break;
            }
            return;
        }
    }
    return;
}
