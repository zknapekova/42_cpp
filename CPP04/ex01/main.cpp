#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
		delete arr[i];
	}
	
	//assignment operator: brain deep copy check
	Dog d1;
	Dog d2;
	d1 = d2;
	std::cout << "Assignment operator: Deep copy check: " << (d1.getBrain() == d2.getBrain()) << std::endl;
	
	//copy constructor: brain deep copy check
	Dog d3(d2);
	std::cout << "Copy constructor: Deep copy check: " << (d2.getBrain() == d3.getBrain()) << std::endl;
	

	return 0;
}
