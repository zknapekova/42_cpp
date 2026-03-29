/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:13:27 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:13:27 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
		
	public:
		AAnimal( void );
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal& orig);
		AAnimal& operator=(const AAnimal& orig);
		
		virtual void	makeSound() const = 0;
		std::string		getType( void ) const;
};


#endif
