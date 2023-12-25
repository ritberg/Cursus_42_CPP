/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/24 19:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(std::string input)
{
    _checkInput(input);
}

RPN::RPN(RPN const & src)
{
    *this = src;
}

RPN::~RPN(void)
{
}

RPN&  RPN::operator=(RPN const & other)
{
    if (this != &other)
        this->_stack = other._stack;
    return (*this);
}

void RPN::_checkInput(std::string & input) const
{
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+'
            && input[i] != '-' && input[i] != '/' && input[i] != '*')
            throw std::invalid_argument("Error");
    } 
}

bool RPN::_isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::_performOperation(int operand1, int operand2, char op)
{
    switch (op)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0)
                throw std::invalid_argument("Impossible to divide by zero");
            return operand1 / operand2;
        default:
            throw std::invalid_argument("Invalid operator, please put +, -, * or /");
    }
}

void RPN::push(int value)
{
    this->_stack.push(value);
}

int RPN::pop(void)
{
    if (!_stack.empty())
    {
        int topValue = _stack.top();
        _stack.pop();
        return (topValue);
    }
    else
        throw std::underflow_error("Stack underflow");
}

void RPN::processInput(const std::string& string)
{
    std::istringstream iss(string);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
            push(atoi(token.c_str()));
        else if (token.length() == 1 && _isOperator(token[0]))
        {
            int operand2 = pop();
            int operand1 = pop();
            int result = _performOperation(operand1, operand2, token[0]);
            push(result);
        }
        else
            throw std::invalid_argument("Invalid token");
    }

    if (this->_stack.size() == 1)
        std::cout << this->_stack.top() << std::endl;
    else
        throw std::invalid_argument("Invalid expression format");
}