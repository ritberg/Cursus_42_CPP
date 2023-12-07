/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
}


Base * generate(void)
{
    int randomValue = rand() % 3;
    switch (randomValue)
    {
        case 0:
            std::cout << YELLOW "A generated" RESET << std::endl;
            return (new A());
        case 1:
            std::cout << GREEN "B generated" RESET << std::endl;
            return (new B());
        case 2:
            std::cout << BLUE "C generated" RESET << std::endl;
            return (new C());
        default:
            return (NULL);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << YELLOW "Type A" RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << GREEN "Type B" RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << BLUE "Type C" RESET << std::endl;
    else
        std::cout << RED "Unknown type" RESET << std::endl;
}

void identify(Base& p)
{   
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << YELLOW "Type A" RESET << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << GREEN "Type B" RESET << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << BLUE "Type C" RESET << std::endl;
    }
    catch(const std::exception& e) {}
}
