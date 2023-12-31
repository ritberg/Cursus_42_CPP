
#ifndef TEST_H
# define TEST_H


# include <iostream>
# include <string>
# include <limits>
# include <cstdlib> 
# include <ctime>
# include <vector>
# include <list>
# include <set>
# include <unordered_set>


class PmergeMe1
{
    public:
        PmergeMe1(void);
        PmergeMe1(PmergeMe1 const & src);
        ~PmergeMe1(void);

        // PmergeMe&  operator=(PmergeMe1 const & other);

        void checkInput(char* input) const;
        void displayResults(void);
        void mergeInsertionSort1(void);
        std::vector<int>& getVector(void);

    private:
        std::vector<int> X;
        std::list<int> list;
        clock_t start, end;
        void _mergeInsertionSort2();
        void insertionSortPairs(std::vector<std::vector<int> >& pairs, size_t index);

        void mergeSortedSequences(std::vector<int>& S, std::vector<int>& B, std::vector<int>& merged);




};


#endif