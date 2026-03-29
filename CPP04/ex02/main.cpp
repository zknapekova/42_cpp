/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:12:42 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:12:42 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


static void	test_comp(bool res, bool expected, std::string name)
{
	std::cout << "TEST: " << name << ": ";
	if (res == expected)
		std::cout << " PASSED\n";
	else
		std::cout << "FAILED: expected: " << expected << ", got: " << res << std::endl;
}

int	main( void )
{
	AAnimal* arr[10];
	size_t i;
	
	for (i = 0; i < 5; i++)
		arr[i] = new Dog();
	for (i = 5; i < 10; i++)
		arr[i] = new Cat();
	
	for (i = 0; i < 10; i++)
	{
		std::cout << i << ": " << arr[i]->getType() << std::endl;
		arr[i]->makeSound();
		std::cout << std::endl;
		delete arr[i];
	}
	
	//Dog: assignment operator: brain deep copy check
	Dog d1;
	Dog d2;
	d1 = d2;
	test_comp(d1.getBrain() == d2.getBrain(), false, "Dog Assignment operator: Brain deep copy check (stack)");
	
	//Dog: copy constructor: brain deep copy check
	Dog d3(d2);
	test_comp(d2.getBrain() == d3.getBrain(), false, "Dog Copy constructor: Brain deep copy check (stack)");
	
	Dog *a = new Dog();
	Dog *b = new Dog(*a);
	
	test_comp(a->getBrain() == b->getBrain(), false, "Dog Copy constructor: Brain deep copy check (heap)");

	delete a;
	delete b;
	
	//Cat: assignment operator: brain deep copy check
	Cat c1;
	Cat c2;
	c1 = c2;
	test_comp(c1.getBrain() == c2.getBrain(), false, "Cat Assignment operator: Brain deep copy check (stack)");
	
	//Cat: copy constructor: brain deep copy check
	Cat c3(c2);
	test_comp(c2.getBrain() == c3.getBrain(), false, "Cat Copy constructor: Brain deep copy check (stack)");
	
	Cat *cp_1 = new Cat();
	Cat *cp_2 = new Cat(*cp_1);
	
	test_comp(cp_1->getBrain() == cp_2->getBrain(), false, "Cat Copy constructor: Brain deep copy check (heap)");

	delete cp_1;
	delete cp_2;
	
	//AAnimal abstract_cls_inst; --> not allowed
	
	return 0;
}
