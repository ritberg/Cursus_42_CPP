/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) 
{
}

Serializer::Serializer(Serializer const & src)
{
}

Serializer::~Serializer(void)
{
}

Serializer&  Serializer::operator=(Serializer const & rhs)
{
    (void)rhs;
    return (*this);
}

std::ostream &	operator<<(std::ostream &out, const Data & obj)
{
    out << "Original data (unsigned int): " << obj.value << std::endl;
    return (out);
}

/************   STATIC METHODS    ************/

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}