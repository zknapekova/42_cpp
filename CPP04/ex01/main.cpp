#include "Animal.hpp"
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
	Animal* arr[10];
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
	
	//assignment operator: brain deep copy check
	Dog d1;
	Dog d2;
	d1 = d2;
	test_comp(d1.getBrain() == d2.getBrain(), false, "Assignment operator: Brain deep copy check (stack)");
	
	//copy constructor: brain deep copy check
	Dog d3(d2);
	test_comp(d2.getBrain() == d3.getBrain(), false, "Copy constructor: Brain deep copy check (stack)");
	
	Dog *a = new Dog();
	Dog *b = new Dog(*a);
	
	test_comp(a->getBrain() == b->getBrain(), false, "Copy constructor: Brain deep copy check (heap)");

	delete a;
	delete b;
		
	return 0;
}
