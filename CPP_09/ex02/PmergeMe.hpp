/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/26 22:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H


# include <iostream>
# include <string>
# include <limits>
# include <cstdlib> 
# include <ctime>
# include <vector>
# include <list>
# include <set>
# include <unordered_set>


class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);

        PmergeMe&  operator=(PmergeMe const & other);

        void checkInput(char* input) const;
        void displayResults(void);
        std::vector<int>& getVector(void);

    private:
        std::vector<int> _X;
        std::list<int> _list;
        clock_t _start, _end;
        void _mergeInsertionSort(std::vector<int>& sequence);
        bool _checkDuplicates(void);


};


#endif