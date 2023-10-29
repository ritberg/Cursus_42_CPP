/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:25:59 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/28 18:26:00 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

//to do: understand references in regards to this code (cf. chat gpt); change file name; args check

bool isString(const std::string& variable)
{
    return (true);
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::ifstream   ifs;
        std::string     s1 = argv[2];
        std::string     s2 = argv[3];
        std::string     line;
        
        ifs.open (argv[1], std::ifstream::in);
        if (!ifs.is_open())
        {
            std::cerr << "Error: no such file." << std::endl;
            return (1);
        }
        std::string     ofsFileName = std::string(argv[1]) + ".replace";
        std::ofstream   ofs(ofsFileName);
    
        while (std::getline(ifs, line))
        {
            size_t  found = line.find(s1);
            while (found != std::string::npos) /* npos = no matches */
            {
                std::string before = line.substr(0, found);
                std::string after = line.substr(found + s1.size());
                line = before + s2 + after;
                found = line.find(s1, found + s2.size());
            }
            ofs << line << std::endl;
        }
        ifs.close();
        ofs.close();
    }
    else
        std::cout << "Error: you should enter a filename and two strings, s1 and s2" << std::endl;
   
    return (0);
}
