/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:09:51 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/18 17:09:53 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {

public:

    PhoneBook(void);
    ~PhoneBook(void);
    class Contact {
    private:
        bool    _check_phone_number(std::string phone_number);
        bool    _check_name_surname(std::string name_surname);

    public:

        void    add_new(void);
        void    search(PhoneBook::Contact contacts[8], int i);
        void    search_index(PhoneBook::Contact contacts[8]);

        std::string name;
        std::string surname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
        Contact(void);
        ~Contact(void);
    };
};


#endif
