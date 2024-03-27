#include <iostream>

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal* meta = new AAnimal();
	const AAnimal* dog = new Dog();
	const AAnimal* i = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	AAnimal* copy = new AAnimal(*i);

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

	std::cout << ibad->getType() << " " << std::endl;
	ibad->makeSound();

	delete ibad;
	delete badmeta;



	return 0;
}
