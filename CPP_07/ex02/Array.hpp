/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <string>
# include <iomanip>

# define RESET	"\e[0m"
# define BLUE   "\033[96m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define VIOLET	"\033[35m"
# define RED "\033[91m"
# define GREY "\033[30m"

template < typename T = unsigned int >
class Array
{
    public:
        Array(void) : _data(NULL), _n(0) {}
        Array(unsigned int n) : _data(new T[n]), _n(n) {}

        Array(Array const & src) : _data(new T[src.size()]), _n(src._n)
        {   
            for (unsigned int i = 0; i < this->size(); ++i)
                this->_data[i] = src._data[i];
        }
        
        ~Array(void) { delete [] _data; }
        Array&  operator=(Array const & rhs)      /// deep copy
        {
            if (this != &rhs)
            {
                if (this->_data)
                    delete[] _data;
                this->_data = new T[this->size()];
                this->_n = rhs._n;
                for (unsigned int i = 0; i < this->size(); ++i)
                    this->_data[i] = rhs._data[i];
            }
            return (*this);
        }

        unsigned int size(void) const { return (this->_n); }

        T& operator[](unsigned int index)            /// subscript operator
        {
            if (index >= this->size())
                throw std::out_of_range("Index out of bounds");
            return (this->_data[index]);
        }

    private:
        unsigned int    _n;
        T*              _data;
};

template <typename T>
std::ostream &	operator<<(std::ostream &out, Array<T> & obj)
{
    out << "Size of the array is " << obj.size() << ", elements of the array are ";
    if (obj.size() == 0)
        out << "0, because it's empty";
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
        if (typeid(obj[i]) != typeid(std::string))
            obj[i] = i + 1;
        out << obj[i] << " ";
    }
    return (out);
}

/*   Surcharge sur l'opérateur << pour les double values  */
// template <>
std::ostream &	operator<<(std::ostream &out, Array<double>& obj)
{
    out << "Size of the array is " << obj.size() << ", elements of the array are ";
    if (obj.size() == 0)
        out << "0, because it's empty";
    for (unsigned int i = 0; i < obj.size(); ++i)
        out << std::setprecision(6) << obj[i] << " ";
    return (out);
}

/*   Surcharge sur l'opérateur << pour les int values  */
// template <>
std::ostream &	operator<<(std::ostream &out, Array<int>& obj)
{
    out << "Size of the array is " << obj.size() << ", elements of the array are ";
    if (obj.size() == 0)
        out << "0, because it's empty";
    for (unsigned int i = 0; i < obj.size(); ++i)
        out << obj[i] << " ";
    return (out);
}

#endif