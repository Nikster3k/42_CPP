/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:07:58 by nsassenb          #+#    #+#             */
/*   Updated: 2024/03/22 15:47:53 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	firstName = std::string();
	lastName = std::string();
	nickname = std::string();
	phonenumber = std::string();
	darkestSecret = std::string();
}

Contact::~Contact(void) {}

bool	Contact::isEmpty(void)
{
	return (firstName.empty() || lastName.empty()
		|| nickname.empty() || phonenumber.empty()
		|| darkestSecret.empty());
}

void	Contact::printInfo(void)
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phonenumber: " << phonenumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string	truncate_string(std::string str, std::size_t len)
{
	if (str.length() > len)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

void	Contact::printListInfo(int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncate_string(firstName, 10) << "|";
	std::cout << std::setw(10) << truncate_string(lastName, 10) << "|";
	std::cout << std::setw(10) << truncate_string(nickname, 10) << "|" << std::endl;
}

void	fixWhiteSpaces(std::string& input)
{
	std::string set = "\t\n\v\f\r";
	std::size_t	i = 0;

	if (input.empty())
		return;
	for (std::size_t x = 0; x < set.length(); x++)
		while ((i = input.find(set.at(x))) < input.length())
			input.replace(i, 1, " ");
	
	while ((i = input.find(' ')) == 0)
		input.replace(i, 1, "");
	while (input.length() > 9
		&& (i = input.find_last_of(' ')) == input.length() - 1)
		input.replace(i, 1, "");
}

std::string	getInput(std::string prompt)
{
	std::string	input = std::string();

	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())	
			return ("");
		fixWhiteSpaces(input);
	}
	return (input);
}

void	Contact::input(void)
{
	firstName = getInput("Enter first name: ");
	if (std::cin.eof())
		return ;
	lastName = getInput("Enter last name: ");
	if (std::cin.eof())
		return ;
	nickname = getInput("Enter nick name: ");
	if (std::cin.eof())
		return ;
	phonenumber = getInput("Enter phonenumber: ");
	if (std::cin.eof())
		return ;
	darkestSecret = getInput("Enter your darkest secret: ");
	if (std::cin.eof())
		return ;
}
