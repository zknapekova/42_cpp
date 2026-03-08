/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:07:50 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:26:03 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	std::cout << "Test 1: 5 zombies created\n";
	{
		Zombie *zomb_arr = zombieHorde(5, "Arnold");
		
		if (!zomb_arr)
			return 1;
		
		for (int i = 0; i < 5; i++)
			zomb_arr[i].announce();
		delete[] zomb_arr;
	}
	
	std::cout << "\nTest 2: No zombies created - no output\n";
	{
		Zombie *zomb_arr = zombieHorde(0, "Arnold");
		
		if (!zomb_arr)
			return 1;
	}
	return 0;
}
