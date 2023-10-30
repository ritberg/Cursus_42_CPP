/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:25:59 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/30 18:26:00 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>

class Harl {
private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
    
public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);
};

const std::string logLevels[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};

#endif