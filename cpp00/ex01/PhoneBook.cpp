/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:08:04 by nsassenb          #+#    #+#             */
/*   Updated: 2024/03/08 09:08:04 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : top(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add(void)
{
	top = top >= 8 ? 0 : top;
	contacts[top].input();
	if (!contacts[top].isEmpty())
		top++;
}

void	PhoneBook::search(void)
{
	std::string	input;

	std::cout << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right)<< "Index" << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right)<< "First name" << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right)<< "Last name" << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right)<< "Nickname" << "|" << std::endl;
	std::cout << "=============================================" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].isEmpty())
			continue ;
		contacts[i].printListInfo(i);
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	int	i = atoi(input.c_str());
	if ((i >= 0 && i < 8) && (!input.empty() && !std::isalpha(input.at(0))) && !contacts[i].isEmpty())
		contacts[i].printInfo();
	else
		std::cout << "Not a valid index!" << std::endl;
}

void	PhoneBook::prompt(void)
{
	std::string	input;

	std::cout << "Welcome to your PhoneBook! Enter (ADD | SEARCH | EXIT)" << std::endl;
	do {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
	}while (input != "EXIT");
}
