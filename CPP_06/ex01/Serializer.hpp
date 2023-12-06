/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <cstdint>

struct Data {
    unsigned int value;
    std::string		string;
    float            fl;

    Data(int val) : value(val) {}
    Data(std::string str) : string(str) {}
    Data(float fl) : fl(fl) {}
};

class Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer const & src);
        ~Serializer(void);
    
    public:
        Serializer&  operator=(Serializer const & rhs);
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

std::ostream &	operator<<(std::ostream &stream, const Data & obj);


#endif