/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/*
&iterPrint<int> or &iterPrint<float> - explicit instanciation 
*/

int main()
{
    std::cout << std::endl << BLUE "*********** int tab[] = {0, 1, 2, 3, 4} ****************" RESET << std::endl;

    int tab[] = {0, 1, 2, 3, 4};
    std::cout << std::endl <<  BLUE "2 ways to call iter():" RESET << std::endl;

    std::cout << std::endl << BLUE <<
            "iter(tab, 5, &iterPrint<int>) - iter function is in the current scope or namespace where it is called" RESET << std::endl;
    iter(tab, 5, &iterPrint<int>);

    std::cout << std::endl << BLUE <<
            "::iter(tab, 5, &iterPrint<int>) - possibility to specify the scope or namespace explicitly" RESET << std::endl;
    ::iter(tab, 5, &iterPrint<int>);

    std::cout << std::endl << GREY "::iterPrint(*tab) - no for loop, so only the first element is printed" RESET << std::endl;
    ::iterPrint(*tab);


    std::cout << std::endl << YELLOW "*********** std::string tab2[] = {\"Hello\", \"World\", \"!\"} ****************" RESET << std::endl;

    std::string tab2[] = {"Hello", "World", "!"};
    ::iter(tab2, 3, &iterPrint<std::string>);


    std::cout << std::endl << GREEN "*********** double tab3[] = {0.04, 1.15, 2.27, 3.38, 4.42} ****************" RESET << std::endl;

    double tab3[] = {0.04, 1.15, 2.27, 3.38, 4.42};
    ::iter(tab3, 5, &iterPrint<double>);


    std::cout << std::endl << VIOLET "*********** float tab4[] = {0.04f, 1.15f, 2.27f, 3.38f, 4.42f} ****************" RESET << std::endl;
    float tab4[] = {0.04f, 1.15f, 2.27f, 3.38f, 4.42f};
    ::iter(tab4, 5, &iterPrint<float>);

    std::cout << std::endl << RED "*********** Empty array ****************" RESET << std::endl;
    int tab5[] = {};
    ::iter(tab5, 0, &iterPrint<int>);
    std::cout << std::endl;

    return (0);
}


//////// MAIN FROM EVAL ////////
/*
class Awsome{

public:
    Awsome(void): _n(42) {return;}
    int get(void)const {return this->_n;}
private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, Awsome const &rhs) {o<<rhs.get(); return o;}

template <typename T>
void print(T const &x){std::cout << x << std::endl; return;}

int main(){
    int tab[] = {0,1,2,3,4};
    Awsome tab2[5];

    iter(tab, 5, print);
    iter(tab2, 5, print);
}
*/