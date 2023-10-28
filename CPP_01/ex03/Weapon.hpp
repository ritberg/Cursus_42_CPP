/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:47:09 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/27 18:47:35 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class	Weapon {

private:
	std::string	_type;

public:
	Weapon(std::string type);
	~Weapon(void);
	std::string const& getType() const;
	void	setType(std::string type);

};

#endif
