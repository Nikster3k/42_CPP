#include <iostream>

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

	std::cout << "=== Given tests ===" << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n\n=== Required tests ===\n" << std::endl;

	Dog dog1 = Dog();
	Dog dog2 = Dog(dog1);

	dog1 = dog2;
	std::cout << std::endl;
	AAnimal* animals[100];
	for (size_t i = 0; i < 50; i++)
	{
		std::cout << "[ " << i << " ]: ";
		animals[i] = new Dog();
		std::cout << std::endl;
	}
	for (size_t i = 50; i < 100; i++)
	{
		std::cout << "[ " << i << " ]: ";
		animals[i] = new Cat();
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "[ " << i << " ]: ";
		delete animals[i];
		std::cout << std::endl;
	}
	
	
	return 0;
}
