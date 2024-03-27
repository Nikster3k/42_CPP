#include <iostream>

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* i = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	Animal* copy = new Animal(*i);

	std::cout << copy->getType() << " " << std::endl;
	*copy = *dog;
	std::cout << copy->getType() << " " << std::endl;

	delete copy;
	delete i;
	delete dog;
	delete meta;

	{
		Dog* a = new Dog();
		Dog* b = new Dog();
		
		*a = *b;
		
		delete a;
		delete b;
	}

	std::cout << "=== Wrong stuff! ===" << std::endl;

	const WrongAnimal*	badmeta = new WrongAnimal();
	const WrongAnimal*	ibad = new WrongCat();
	WrongCat	wcat = WrongCat();

	std::cout << ibad->getType() << " " << std::endl;
	ibad->makeSound();
	wcat.makeSound();
	
	delete ibad;
	delete badmeta;

	return 0;
}
