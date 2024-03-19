#include <iostream>

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Animal* copy = new Animal(*i);

	std::cout << copy->getType() << " " << std::endl;
	*copy = *j;
	std::cout << copy->getType() << " " << std::endl;

	delete copy;
	delete i;
	delete j;
	delete meta;

	std::cout << "=== Wrong stuff! ===" << std::endl;

	const WrongAnimal*	badmeta = new WrongAnimal();
	const WrongAnimal*	ibad = new WrongCat();

	std::cout << ibad->getType() << " " << std::endl;
	ibad->makeSound();

	delete ibad;
	delete badmeta;

	return 0;
}
