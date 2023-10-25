/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:26:25 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/18 17:26:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Constructor phonebook called" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Destructor phonebook called" << std::endl;
    return;
}