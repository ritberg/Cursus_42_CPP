
#include "test.hpp"

PmergeMe1::PmergeMe1(void)
{
}

PmergeMe1::PmergeMe1(PmergeMe1 const & src)
{
    *this = src;
}

PmergeMe1::~PmergeMe1(void)
{
}

std::vector<int>& PmergeMe1::getVector(void)
{
    return (this->X);
}

void PmergeMe1::checkInput(char* input) const
{
    for (size_t i = 0; i < strlen(input); ++i)
    {
        if (!isdigit(input[i]))
            throw std::invalid_argument("Error: not a positive integer");
    }
    if (std::atoi(input) < 0)
        throw std::invalid_argument("Error: atoi() failed");
}

void PmergeMe1::insertionSortPairs(std::vector<std::vector<int> >& pairs, size_t index) {
    if (index >= pairs.size())
        return;

    std::vector<int>& pair = pairs[index];
    if (pair[0] > pair[1]) {
        std::swap(pair[0], pair[1]);
    }

    insertionSortPairs(pairs, index + 1);
}

void PmergeMe1::_mergeInsertionSort2(void)
{
    if (X.size() <= 1)
        return;

    int straggler = -1;
    if (!X.empty() && X.size() % 2 != 0)
    {
        straggler = X.back();
        X.pop_back();
    }

    std::vector<std::vector<int> > pairs;
    for (size_t i = 0; i < X.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(X[i]);
        pair.push_back((i + 1 < X.size()) ? X[i + 1] : X[i]);
        pairs.push_back(pair);
    }

    insertionSortPairs(pairs, 0);


//print
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << "Pair " << i + 1 << ": ";
        for (size_t j = 0; j < pairs[i].size(); ++j)
            std::cout << pairs[i][j] << " ";
        std::cout << std::endl;
    }

    std::vector<int> S;
    std::vector<int> B;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        S.push_back(pairs[i][0]);
        B.push_back(pairs[i][1]);
    }

    std::sort(S.begin(), S.end());
    std::sort(B.begin(), B.end());

    // Merge S and B into a new vector
    std::vector<int> merged(S.size() + B.size());
    std::merge(S.begin(), S.end(), B.begin(), B.end(), merged.begin());

    // Remove duplicates
    std::vector<int>::iterator it = std::unique(merged.begin(), merged.end());
    merged.erase(it, merged.end());

    // Display the merged vector
    std::cout << "Merged and sorted vector without duplicates:" << std::endl;
    for (std::vector<int>::iterator iter = merged.begin(); iter != merged.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;


    // Display the content of sequences S and B
    std::cout << "Content of sequence S:" << std::endl;
    for (size_t i = 0; i < S.size(); ++i)
        std::cout << S[i] << " ";
    std::cout << std::endl;


    std::cout << "Content of sequence B:" << std::endl;
    for (size_t i = 0; i < B.size(); ++i)
        std::cout << B[i] << " ";
    std::cout << std::endl;

    X = merged;
}

void PmergeMe1::displayResults()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < X.size(); ++i)
        std::cout << X[i] << " ";

    std::cout << std::endl;

    start = clock();
    _mergeInsertionSort2();
    end = clock();

    std::cout << "After (std::vector): ";
    for (size_t i = 0; i < X.size(); ++i)
        std::cout << X[i] << " ";

    std::cout << "Time to process a range of " << X.size() << " elements with std::vector: "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

    std::cout << std::endl;
}
