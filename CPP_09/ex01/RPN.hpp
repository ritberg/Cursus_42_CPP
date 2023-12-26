/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/24 19:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class RPN
{
    public:
        RPN(void);
        RPN(std::string input);
        RPN(RPN const & src);
        ~RPN(void);

        RPN&    operator=(RPN const & other);

        void    processInput(const std::string & string);

    private:
        std::stack<int> _stack;

        void    _checkInput(std::string & input) const;
        void    _additionalCheck(std::string & input) const;
        bool    _isOperator(char c);
        int     _performOperation(int operand1, int operand2, char op);

        void    push(int value);
        int     pop(void);

};

#endif