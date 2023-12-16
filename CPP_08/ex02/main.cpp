/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << std::endl << YELLOW "************ SUBJECT TEST improved ***************" RESET << std::endl << std::endl;

    MutantStack<int> mstack;
    std::cout << "adding 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack top after popping: " << mstack.top() << std::endl;
    std::cout << "mstack stack size: " << mstack.size() << " (only 1 element left)" << std::endl;
    std::cout << "adding 3, 6, 737, 34587, 0" << std::endl;
    mstack.push(3);
    mstack.push(6);
    mstack.push(737);
    mstack.push(34587);
    mstack.push(0);


    std::cout << std::endl << VIOLET "----testing iterators----" RESET << std::endl;
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << std::endl << VIOLET "current it" RESET << std::endl;
    std::cout << *it << std::endl;
    std::cout << std::endl << VIOLET "++it" RESET << std::endl;
    ++it;
    std::cout << *it << std::endl;
    std::cout << std::endl << VIOLET "--it" RESET << std::endl;
    --it;
    std::cout << *it << std::endl;

    std::cout << std::endl << VIOLET "while (it != ite), ++it" RESET << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << std::endl << VIOLET "----stack of mstack----" RESET << std::endl << std::endl;

    std::stack<int> s(mstack);
    if (!s.empty())
        std::cout << "is not empty" << std::endl;


    std::cout << std::endl << VIOLET "----printing the mstack content----" RESET << std::endl << std::endl;

    std::cout << mstack << std::endl;


    std::cout << std::endl << YELLOW "************ OTHER TESTS ***************" RESET << std::endl << std::endl;
    // MutantStack<double> m;
    // mstack.push(3.7);
    // mstack.push(5.2);
    // std::cout << "m top: " << mstack.top() << std::endl;


/*
    std::cout << std::endl << VIOLET "----c++11----" RESET << std::endl << std::endl;

    MutantStack<int> secStack;
    secStack.push(543553);
    secStack.push(-3);

    std::cout << GREEN "mstack top before swaping: " RESET << mstack.top() << std::endl;
    std::cout << GREEN "secStack top before swaping: " RESET << secStack.top() << std::endl << std::endl;
    std::cout << BLUE "mstack size before swaping: " RESET << mstack.size() << std::endl;
    std::cout << BLUE "secStack size before swaping: " RESET << secStack.size() << std::endl << std::endl;

    mstack.swap(secStack);

    std::cout << GREEN "mstack top after swaping: " RESET << mstack.top() << std::endl;
    std::cout << GREEN "secStack top after swaping: " RESET << secStack.top() << std::endl << std::endl;
    std::cout << BLUE "mstack size after swaping: " RESET << mstack.size() << std::endl;
    std::cout << BLUE "secStack size after swaping: " RESET << secStack.size() << std::endl;
*/
    return (0);
}