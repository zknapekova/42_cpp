/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:14:59 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:59 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class Cat: public Animal
{
	public:
		Cat( void );
		~Cat( );
		Cat( const Cat& orig);
		Cat& operator=(const Cat& orig);
		
		void makeSound( void ) const;
};

#endif
