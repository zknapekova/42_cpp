/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:13:16 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:13:16 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	Brain* _brain;
	
	public:
		Dog( void );
		~Dog( );
		Dog( const Dog& orig);
		Dog& operator=(const Dog& orig);
		
		void makeSound( void ) const;
		const Brain* getBrain(void) const;
};

#endif
