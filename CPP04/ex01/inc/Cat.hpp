/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:14:19 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:19 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	Brain*	_brain;
	
	public:
		Cat( void );
		~Cat( );
		Cat( const Cat& orig);
		Cat& operator=(const Cat& orig);
		
		void makeSound( void ) const;
		const Brain* getBrain(void) const;
};

#endif
