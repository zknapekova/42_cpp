/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:10:28 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:10:28 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(int argc, char *argv[])
{
	Harl harl;
	
	if (argc!= 2)
	{
		std::cout << "Invalid number of arguments\n";
		return 1;
	}
	
	harl.complain(argv[1]);
	
	return 0;
}
