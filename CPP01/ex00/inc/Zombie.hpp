/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:07:35 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:07:35 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie 
{
	std::string name;
	
	public:
		void announce( void );
		Zombie(std::string _name);
		~Zombie( void );
};

Zombie *newZombie( std::string name);
void	randomChump( std::string name);


#endif
