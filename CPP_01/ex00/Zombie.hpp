/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:57:05 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/25 19:01:42 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

/* Zombie class */
class Zombie {

public:
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
	
private:
	std::string	_name;

};

/* Function declarations */
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
