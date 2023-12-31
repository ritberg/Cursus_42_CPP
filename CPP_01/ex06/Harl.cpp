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

/* better version : */
void Harl::complain(std::string level)
{
    int levelIndex = -1;

    for (int i = 0; i < 4; i++)
    {
       if (logLevels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

 switch (levelIndex)
    {
        case 0:
            _debug();
        case 1:
            _info();
        case 2:
            _warning();
        case 3:
            _error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

/* I submitted this, not the best version :
void Harl::complain(std::string level)
{
    int levelIndex = -1;

    for (int i = 0; i < 4; i++)
    {
       if (logLevels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

    if (levelIndex == -1)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

 switch (levelIndex)
    {
        case 0:
            _debug();
        case 1:
            _info();
        case 2:
            _warning();
        case 3:
            _error();
            break;
        default:
            std::cout << "[ Unknown log level ]" << std::endl;
    }
}
*/
