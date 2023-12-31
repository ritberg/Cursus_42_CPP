/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
About ex00:
Static_cast is used for most type conversions,
especially those not involving polymorphism.
*/
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "❕Usage: " << argv[0] << " <literal>" << std::endl;
        return (1);
    }

    ScalarConverter::convert(argv[1]);

    return (0);
}