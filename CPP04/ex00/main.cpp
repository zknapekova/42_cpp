#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	const Animal *meta = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	
	std::cout << meta->getType() << ": " << std::endl;
	meta->makeSound();
	
	std::cout << cat->getType() << ": " << std::endl;
	cat->makeSound();
	
	std::cout << dog->getType() << ": " << std::endl;
	dog->makeSound();
	
	std::cout << meta->getType() << ": " << std::endl;
	meta->makeSound();
	
	
	const WrongAnimal *w_anim = new WrongCat();
	std::cout << w_anim->getType() << ": " << std::endl;
	w_anim->makeSound();
	delete w_anim;
	
	const WrongCat w_cat = WrongCat();
	w_anim = &w_cat;
	std::cout << w_anim->getType() << ": " << std::endl;
	w_anim->makeSound();
	
	delete meta;
	delete cat;
	delete dog;
	return 0;
}
