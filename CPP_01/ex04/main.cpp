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

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::ifstream   ifs;
        if ((std::string(argv[2])).empty() && (std::string(argv[3])).empty()) /* return 1 if there are no strings */
            return (1);
        std::string     s1 = argv[2];
        std::string     s2 = argv[3];
        std::string     line;
        ifs.open (argv[1], std::ifstream::in);
        if ((!ifs.is_open()) || ifs.fail()) /* return 1 if no file or cannot open */
        {
            std::cerr << "Error: no such file or permission denied." << std::endl;
            return (1);
        }
        std::string     ofsFileName = std::string(argv[1]) + ".replace"; /* <filename>.replace */
        std::ofstream   ofs(ofsFileName);

        while (std::getline(ifs, line)) /* replace s1 by s2 */
        {
            size_t  found = line.find(s1);
            while (found != std::string::npos) /* npos = no matches */
            {
                std::string before = line.substr(0, found);
                std::string after = line.substr(found + s1.size());
                line = before + s2 + after;
                found = line.find(s1, found + s2.size());
            }
            ofs << line << std::endl; /* put the line (modified or not) in the <filename>.replace file */
        }
        ifs.close();
        ofs.close();
    }
    else
        std::cout << "Error: you should enter a filename and two strings, s1 and s2" << std::endl;
    return (0);
}
