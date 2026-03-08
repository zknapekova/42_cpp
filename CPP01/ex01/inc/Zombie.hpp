/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:07:42 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:24:13 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie 
{
	std::string name;
	
	public:
		void announce( void );
		void set_name( std::string name ) ;
		Zombie(std::string _name = "");
		~Zombie( void );
};

Zombie	*zombieHorde(int N, std::string name);

#endif
