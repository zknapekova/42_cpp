/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:13:56 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:13:56 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain& orig)
{
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = orig.ideas[i];
}
	
Brain& Brain::operator=(const Brain& orig)
{
	std::cout << "Brain assignment operator" << std::endl;

    if (this != &orig)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = orig.ideas[i];
    }
    return *this;
}




