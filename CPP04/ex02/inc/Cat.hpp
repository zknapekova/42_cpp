/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:13:19 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:13:19 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
