#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
	_brain = new(std::nothrow) Brain;
	if (!_brain)
    	std::cerr << "Brain allocation failed!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor constructor" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& orig):
	AAnimal(orig)
{
	std::cout << "Dog copy constructor" << std::endl;
	_brain = new(std::nothrow) Brain(*orig._brain);
	if (!_brain)
		std::cerr << "Brain allocation failed!" << std::endl;

}

Dog& Dog::operator=(const Dog& orig)
{
	std::cout << "Dog copy assignment operator" << std::endl;
	
	if (this != &orig)
	{
		AAnimal::operator=(orig);
		delete _brain;
		_brain = new(std::nothrow) Brain(*orig._brain);
		if (!_brain)
			std::cerr << "Brain allocation failed!" << std::endl;
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "bark" << std:: endl;
}

const Brain* Dog::getBrain(void) const
{
	return _brain;
}
