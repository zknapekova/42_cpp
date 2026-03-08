/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:07:15 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 16:18:23 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	zombie1("Zombie1");
	zombie1.announce();
	
	Zombie *zombie2 = newZombie("Zombie2");
	zombie2->announce();
	delete zombie2;
	
	randomChump("Zombie3");
}
