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

	std::cout << std::endl << VIOLET "----MutantStack with a list----" RESET << std::endl << std::endl;

    MutantStack< std::list<int> > mlist;
    // std::cout << "adding 5, 17 with push_front" << std::endl;
	// mlist.push_front(5);
	// mlist.push_front(17);
	// std::cout << "top is: " << mlist.top() << std::endl;
	// std::cout << "size is: " << mlist.size() << std::endl;
    // std::cout << "adding 3, 4, 7, 9 with push_back" << std::endl;
	// mlist.push_back(3);
	// mlist.push_back(4);
	// mlist.push_back(7);
	// mlist.push_back(9);
    // std::cout << "top is: " << mlist.top() << std::endl;

	// std::list<int>::iterator itl = mlist.begin();
	// std::list<int>::iterator itle = mlist.end();

    // std::cout << std::endl << VIOLET "current itl" RESET << std::endl;
    // std::cout << *itl << std::endl;
    // std::cout << std::endl << VIOLET "++itl" RESET << std::endl;
	// ++itl;
    // std::cout << *itl << std::endl;
    // std::cout << std::endl << VIOLET "--itl" RESET << std::endl;
	// --itl;
    // std::cout << *itl << std::endl;

    // std::cout << std::endl << VIOLET "while (itl != itle), ++itl" RESET << std::endl;
	// while (itl != itle)
	// {
	// 	std::cout << *itl << std::endl;
	// 	++itl;
	// }


    std::cout << std::endl << VIOLET "----mutantStr with strings, printing the mutantStr content----" RESET << std::endl << std::endl;

    MutantStack<std::string> mutantStr;
    mutantStr.push("hi");
    mutantStr.push("hjkwhfke");
    mutantStr.push("dddddd");
    std::cout << mutantStr << std::endl;


    std::cout << std::endl << VIOLET "----mutantStr - testing reverse iterators----" RESET << std::endl << std::endl;

    MutantStack<std::string> mutS;
    mutS.push("first");
    mutS.push("second");
    mutS.push("third");

    std::cout << mutS << std::endl;

    std::cout << "Forward iteration:" << std::endl;
    for (MutantStack<std::string>::iterator it = mutS.begin(); it != mutS.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl << std::endl << "Reverse iteration:" << std::endl;
    for (MutantStack<std::string>::reverse_iterator it = mutS.rbegin(); it != mutS.rend(); ++it)
        std::cout << *it << " ";

    MutantStack<std::string>::reverse_iterator it1 = mutS.rbegin();

    std::cout << std::endl << std::endl << VIOLET "current it" RESET << std::endl;
    std::cout << *it1 << std::endl;
    std::cout << std::endl << VIOLET "++it" RESET << std::endl;
    ++it1;
    std::cout << *it1 << std::endl;
    std::cout << std::endl << VIOLET "--it" RESET << std::endl;
    --it1;
    std::cout << *it1 << std::endl;

    std::cout << std::endl;


    std::cout << std::endl << YELLOW "*********** MutantStack with doubles - assignment operator = test ************" RESET << std::endl << std::endl;

    MutantStack<double> mutD;
    mutD.push(1.1);
    mutD.push(2.2);
    MutantStack<double> tmp = mutD;
    std::cout << mutD << std::endl;
    std::cout << tmp << std::endl;


    std::cout << YELLOW "*********** MutantStack with doubles - copy constructor test ************" RESET << std::endl;

    MutantStack<double> original;
    original.push(-6767.7);

    MutantStack<double> copy(original);

    std::cout << std::endl << "Original object: " << std::endl << original << std::endl;
    std::cout << "Copied object: " << std::endl << copy << std::endl;



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