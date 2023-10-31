/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
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

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
        return (1);
    else
        harl.complain(argv[1]);
    return (0);
}

/* OLD
int main(int argc, char **argv)
{
    Harl harl;
    int found_levels_flag = 0;

    if (argc == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            if (logLevels[i] == argv[1])
            {
                for (int j = i; j < 4; j++)
                    harl.complain(logLevels[j]);
                found_levels_flag = 1;
            }
        }
        if (found_levels_flag == 0)
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return (0);
}
*/