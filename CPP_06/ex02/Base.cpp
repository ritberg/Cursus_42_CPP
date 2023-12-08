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
    int randomValue = rand() % 3; // generate a random number in the range [0, 2]
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

/*
The usage of dynamic_cast in the identify(Base* p) function
is a common way to determine the actual type of the object
pointed to by the Base pointer at runtime.

dynamic_cast is used for downcasting a base class pointer to a child class
*/
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

/*
If/else are not ok here because `(void)dynamic_cast<A&>(p)` is not a boolean expression.
(void) is a cast to void and discards the result of the dynamic cast.
(void) is used to silence compiler warnings.

dynamic_cast is used for upcasting a base class reference to a derived class pointer
*/
void identify(Base& p)
{   
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << YELLOW "Type A" RESET << std::endl;
    }
    catch(const std::exception&)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << GREEN "Type B" RESET << std::endl;
    }
    catch(const std::exception&)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << BLUE "Type C" RESET << std::endl;
    }
    catch(const std::exception&)
    {
    }
}
