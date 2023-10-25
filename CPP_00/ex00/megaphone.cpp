/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:55:59 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/18 11:56:01 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cctype> 

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else if (argc > 1)
    {
        argv++;
        while (*argv)
        {
            char *argv_char = *argv;
            while (*argv_char)
            {
                std::cout << (char)toupper(*argv_char);
                argv_char++;
            }
            argv++;
        }
        std::cout << std::endl;
    }
    return (0);
}
