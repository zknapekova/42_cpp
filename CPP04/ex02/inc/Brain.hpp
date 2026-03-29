/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:13:24 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:13:24 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	std::string ideas[100];
	
	public:
		Brain();
		~Brain();
		Brain(const Brain& orig);
		Brain&	operator=(const Brain& orig);
};


#endif
