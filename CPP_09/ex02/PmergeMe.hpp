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


class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);

        // PmergeMe&  operator=(PmergeMe const & other);

        void checkInput(char* input) const;

};

#endif