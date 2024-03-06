#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	top = 0;
}

void	PhoneBook::Prompt(void)
{
	std::string	input;

	std::cout << "Welcome to your PhoneBook! Enter (ADD | SEARCH | EXIT)" << std::endl;
	do {
		std::cout << "> ";
		std::cin >> input;
		std::cin.clear();
		if (input == "ADD")
		{
			top = top >= 8 ? 0 : top;
			contacts[top++].Input();
		}
		else if (input == "SEARCH")
		{
			for (int i = 0; i < 8; i++)
			{
				if (contacts[i].IsEmpty())
					continue ;
				contacts[i].PrintListInfo(i);
			}
			std::cout << "Enter index: ";
			std::cin >> input;
			int	i = atoi(input.c_str());
			if ((i >= 0 && i < 8) && !std::isalpha(input.at(0)) && !contacts[i].IsEmpty())
				contacts[i].PrintInfo();
			else
				std::cout << "Not a valid index!" << std::endl;

		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}while (input != "EXIT");
}