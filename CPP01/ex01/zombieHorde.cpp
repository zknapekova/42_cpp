/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:02 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:08:02 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	
	Zombie *arr = new(std::nothrow) Zombie[N];
	if (!arr)
		return NULL;
		
	for (int i = 0; i < N; i++)
		arr[i].set_name(name);
		
	return arr;
}
