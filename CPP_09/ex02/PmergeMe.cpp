/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/26 22:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    *this = src;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe&  PmergeMe::operator=(PmergeMe const & other)
{
    if (this != &other)
    {
        this->_X = other._X;
        this->_list = other._list;
    }
    return (*this);
}

std::vector<int>& PmergeMe::getVector(void)
{
    return (this->_X);
}

std::list<int>& PmergeMe::getList(void)
{
    return (this->_list);
}

void PmergeMe::checkInput(char* input) const
{
   if (std::atoi(input) < 0)
        throw std::invalid_argument("Error: atoi() failed");

    for (size_t i = 0; i < strlen(input); ++i)
    {
        if (!isdigit(input[i]))
            throw std::invalid_argument("Error: not a positive integer");
    }
}

bool PmergeMe::_checkDuplicates(void)
{
    std::set<int> uniqueElemsV;
    std::set<int> uniqueElemsL;
    for (std::vector<int>::const_iterator it = _X.begin(); it != _X.end(); ++it)
    {
        if (!uniqueElemsV.insert(*it).second) // if the insertion of the current digit fails 
            return (true);                   // (meaning it's already present in the set), return true
    }
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it)
    {
        if (!uniqueElemsL.insert(*it).second)
            return (true);
    }
    return (false);  // No duplicates
}

bool _compare(int a, int b)
{
    return a < b;
}

/*
Function to perform Merge-Insertion Sort:
1. If the size %2 != 0, remove the last element and stock it as int straggler
2. Group elements into pairs
3. Determine the larger of the two elements in each pair
4. Recursively sort the larger elements
5. Insert the element paired with the first and smallest element of S at the start of S
6. Insert remaining elements into S with a specially chosen insertion ordering
7. Use binary search to find the correct position for insertion
8. Add straggler if the sequence was odd
9. Copy the sorted sequence back to the original array
*/ 
void PmergeMe::_mergeInsertionSortVector(std::vector<int>& X)
{
    if (X.size() <= 1)
        return;

    int straggler = -1;
    if (!X.empty() && X.size() % 2 != 0) // 1
    {
        straggler = X.back();
        X.pop_back();
    }

    std::vector<int> S;
    for (size_t i = 0; i < X.size(); i += 2) // 2
    {
        int larger = std::max(X[i], X[i + 1]);  // 3
        // std::cout << "X: " << X[i] << std::endl;
        // std::cout << "X+1: " << X[i + 1] << std::endl;
        // std::cout << "Larger: " << larger << std::endl;
        if (std::find(S.begin(), S.end(), larger) == S.end())
            S.push_back(larger);
    }

    _mergeInsertionSortVector(S);  // 4

    int smallestElement = *std::min_element(X.begin(), X.end()); // 5
    S.insert(S.begin(), smallestElement);

    for (size_t i = 0; i < X.size(); ++i) // 6
    {
        if (X[i] != smallestElement)
        {
            std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), X[i], _compare); // 7
            if (std::find(S.begin(), S.end(), X[i]) == S.end())
                S.insert(pos, X[i]);
        }
    }
    if (straggler != -1) // 8
    {
        std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler, _compare);
        S.insert(pos, straggler);
    }

    X = S; // 9
}

void PmergeMe::_mergeInsertionSortList(std::list<int>& list)
{
    if (list.size() <= 1)
        return;

    int straggler = -1;
    if (!list.empty() && list.size() % 2 != 0)
    {
        straggler = list.back();
        list.pop_back();
    }

    std::list<int> S;
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        int larger = std::max(*it, *(std::next(it)));
        if (std::find(S.begin(), S.end(), larger) == S.end())
            S.push_back(larger);
        std::advance(it, 2);
    }

    _mergeInsertionSortList(S);

    int smallestElement = *std::min_element(list.begin(), list.end());
    S.insert(S.begin(), smallestElement);

    for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
    {
        if (*i != smallestElement)
        {
            std::list<int>::iterator pos = std::lower_bound(S.begin(), S.end(), *i, _compare);
            if (std::find(S.begin(), S.end(), *i) == S.end())
                S.insert(pos, *i);
        }
    }
    if (straggler != -1)
    {
        std::list<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler, _compare);
        S.insert(pos, straggler);
    }

    list = S;
}

void PmergeMe::displayResults()
{
    if (_checkDuplicates() == true)
        throw std::invalid_argument("Error: duplicates");

    std::cout << BLUE "--------- std::vector --------- " << std::endl;
    std::cout << std::endl << BLUE "Before: ";
    for (size_t i = 0; i < _X.size(); ++i)
        std::cout << _X[i] << " ";

    std::cout << std::endl;

    _start = clock();
    _mergeInsertionSortVector(_X);
    _end = clock();

    std::cout << BLUE "After: ";
    for (size_t i = 0; i < _X.size(); ++i)
        std::cout << _X[i] << " ";

    std::cout << std::endl;

    std::cout << BLUE "Time to process a range of " << _X.size() << " elements with std::vector: "
              << (static_cast<double>(_end - _start) / CLOCKS_PER_SEC) * 1000 << " ms" RESET << std::endl;

    std::cout << RESET << std::endl;

    std::cout << GREEN "---------- std::list ---------- " << std::endl;
    std::cout << std::endl << GREEN "Before: ";
    for (std::list<int>::iterator itPrint = _list.begin(); itPrint != _list.end(); ++itPrint)
        std::cout << *itPrint << " ";

    _start1 = clock();
    _mergeInsertionSortList(_list);
    _end1 = clock();

    std::cout << std::endl;

    std::cout << GREEN "After: ";
    for (std::list<int>::iterator itOut = _list.begin(); itOut != _list.end(); ++itOut)
        std::cout << *itOut << " ";

    std::cout << std::endl;

    std::cout << GREEN "Time to process a range of " << _list.size() << " elements with std::list: "
              << (static_cast<double>(_end1 - _start1) / CLOCKS_PER_SEC) * 1000 << " ms" RESET << std::endl;
    
    std::cout << RESET << std::endl;
}
