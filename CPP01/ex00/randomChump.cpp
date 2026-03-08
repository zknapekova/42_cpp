/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:07:26 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:07:26 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump( std::string name)
{
	Zombie *new_zombie = newZombie(name);
	new_zombie->announce();
	
	delete new_zombie;
}
