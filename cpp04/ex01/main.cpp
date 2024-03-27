#include <iostream>

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Given tests ===" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n\n=== Required tests ===\n" << std::endl;

	{
		Dog dog1 = Dog();
		dog1.setIdeas("food");
		std::cout << "\nDog1 assigned ideas: " << std::endl;
		dog1.printBrain();
		Dog dog2 = Dog(dog1);
		std::cout << "\nDog2 copied ideas: " << std::endl;
		dog2.printBrain();
		dog2.setIdeas("ball");
		std::cout << "\nDog2 new ideas: " << std::endl;
		dog2.printBrain();
		std::cout << "\nDog1 old assigned ideas: " << std::endl;
		dog1.printBrain();
		dog1 = dog2;
		std::cout << "\nDog1 after copy assignment ideas: " << std::endl;
		dog1.printBrain();
	}

	{
		Cat cat1 = Cat();
		cat1.setIdeas("push cup off table");
		std::cout << "\nCat1 assigned ideas: " << std::endl;
		cat1.printBrain();
		Cat cat2 = Cat(cat1);
		std::cout << "\nCat2 copied ideas: " << std::endl;
		cat2.printBrain();
		cat2.setIdeas("kill owner");
		std::cout << "\nCat2 new ideas: " << std::endl;
		cat2.printBrain();
		std::cout << "\nCat1 old assigned ideas: " << std::endl;
		cat1.printBrain();
		cat1 = cat2;
		std::cout << "\nCat1 after copy assignment ideas: " << std::endl;
		cat1.printBrain();
	}

	std::cout << "\n\n=== Array tests ===\n" << std::endl;

	Animal* animals[10];
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "[ " << i << " ]: ";
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}
	
	for (size_t i = 0; i < 10; i++)
		animals[i]->makeSound();

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "[ " << i << " ]: ";
		delete animals[i];
		std::cout << std::endl;
	}
	
	
	return 0;
}
