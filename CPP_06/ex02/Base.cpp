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
            std::cout << "A generated" << std::endl;
            return (new A());
        case 1:
            std::cout << "B generated" << std::endl;
            return (new B());
        case 2:
            std::cout << "C generated" << std::endl;
            return (new C());
        default:
            return (NULL);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    identify(&p);
}
