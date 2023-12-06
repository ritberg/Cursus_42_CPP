/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:56:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{   
/*
1. Create an instance of the Data structure
2. Use serialize() on the address of the Data object
3. Pass the return value of serialize() method to deserialize() method
4. Ensure the return value of deserialize() compares equal to the original pointer
*/

    std::cout << std::endl << "------------- 42 --------------" << std::endl << std::endl;

    Data originalData(42);

    uintptr_t serializedValue = Serializer::serialize(&originalData);

    Data* deserializedData = Serializer::deserialize(serializedValue);

    if (deserializedData == &originalData)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;

    std::cout << "Original data: " << originalData.value << std::endl;
    std::cout << "Deserialized data: " << deserializedData->value << std::endl;



    std::cout << std::endl << "------------- \"hello\" ---------------" << std::endl << std::endl;

    Data originalData1("hello");

    uintptr_t serializedValue1 = Serializer::serialize(&originalData1);

    Data* deserializedData1 = Serializer::deserialize(serializedValue1);

    if (deserializedData1 == &originalData1)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;

    std::cout << "Original data: " << originalData1.string << std::endl;
    std::cout << "Deserialized data: " << deserializedData1->string << std::endl;



    std::cout << std::endl << "------------- 42.42f --------------" << std::endl << std::endl;

    Data originalData2(42.42f);

    uintptr_t serializedValue2 = Serializer::serialize(&originalData2);

    Data* deserializedData2 = Serializer::deserialize(serializedValue2);

    if (deserializedData2 == &originalData2)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;

    std::cout << "Original data: " << originalData2.fl <<"f" << std::endl;
    std::cout << "Deserialized data: " << deserializedData2->fl << "f" << std::endl;

    

    // std::cout << std::endl << "------------- WEIRD --------------" << std::endl << std::endl;

    // Data originalData3(999999999999);

    // uintptr_t serializedValue3 = Serializer::serialize(&originalData3);

    // Data* deserializedData3 = Serializer::deserialize(serializedValue3);

    // if (deserializedData3 == &originalData3)
    //     std::cout << "Serialization and deserialization successful!" << std::endl;
    // else
    //     std::cout << "Serialization and deserialization failed!" << std::endl;

    // std::cout << "Original data: " << originalData3.value <<"f" << std::endl;
    // std::cout << "Deserialized data: " << deserializedData3->value << "f" << std::endl;


    std::cout << std::endl << "------------- = operator --------------" << std::endl << std::endl;

    std::cout << originalData << std::endl;


    return (0);
}