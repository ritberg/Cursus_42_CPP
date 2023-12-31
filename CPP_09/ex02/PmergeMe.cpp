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

std::vector<int>& PmergeMe::getVector(void)
{
    return (this->X);
}

void PmergeMe::checkInput(char* input) const
{
    for (size_t i = 0; i < strlen(input); ++i)
    {
        if (!isdigit(input[i]))
            throw std::invalid_argument("Error: not a positive integer");
    }
    if (std::atoi(input) < 0)
        throw std::invalid_argument("Error: atoi() failed");
}

// Custom comparison function for sorting
bool _compare(int a, int b)
{
    return a < b;
}

// Function to perform Merge-Insertion Sort
void PmergeMe::_mergeInsertionSort2(std::vector<int>& X)
{
    // Base case: if the size of the input is 1 or less, it's already sorted
    if (X.size() <= 1)
        return;

    int straggler = -1;
    if (!X.empty() && X.size() % 2 != 0)
    {
        straggler = X.back();
        X.pop_back();
    }

    // Step 1: Group elements into pairs
    std::vector<int> S;
    for (size_t i = 0; i < X.size(); i += 2)
    {
        // Step 2: Determine the larger of the two elements in each pair
        int larger = std::max(X[i], X[i + 1]);
        // std::cout << "X: " << X[i] << std::endl;
        // std::cout << "X+1: " << X[i + 1] << std::endl;
        // std::cout << "Larger: " << larger << std::endl;
        if (std::find(S.begin(), S.end(), larger) == S.end())
            S.push_back(larger);
    }

    // Step 3: Recursively sort the larger elements
    _mergeInsertionSort2(S);

    // Step 4: Insert the element paired with the first and smallest element of S at the start of S
    int smallestElement = *std::min_element(X.begin(), X.end());
    S.insert(S.begin(), smallestElement);

    // Step 5: Insert remaining elements into S with a specially chosen insertion ordering
    for (size_t i = 0; i < X.size(); ++i)
    {
        if (X[i] != smallestElement)
        {
            // Use binary search to find the correct position for insertion
            std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), X[i], _compare);
            if (std::find(S.begin(), S.end(), X[i]) == S.end())
                S.insert(pos, X[i]);
        }
    }
    if (straggler != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler, _compare);
        S.insert(pos, straggler);
    }

    // Copy the sorted sequence back to the original array
    X = S;
}

void PmergeMe::mergeInsertionSort1()
{
    // Perform Merge-Insertion Sort on vector
    start = clock();
    _mergeInsertionSort2(X);
    end = clock();
    
    // Display the sorted sequence for the vector
    std::cout << "After (std::vector): ";
    for (size_t i = 0; i < X.size(); ++i)
        std::cout << X[i] << " ";
    
    std::cout << std::endl;

    // Display the time used by the algorithm with the first container (vector)
    std::cout << "Time to process a range of " << X.size() << " elements with std::vector: "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

}

void PmergeMe::displayResults()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < X.size(); ++i)
        std::cout << X[i] << " ";

    std::cout << std::endl;

    mergeInsertionSort1();
}
