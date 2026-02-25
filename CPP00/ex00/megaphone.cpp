/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:30:26 by zuknapek          #+#    #+#             */
/*   Updated: 2026/02/15 15:07:49 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i <= argc - 1; i++)
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (std::islower(argv[i][j]))
				std::cout << char(argv[i][j] - 'a' + 'A');
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return 0;
}
