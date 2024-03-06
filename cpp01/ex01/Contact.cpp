#include "Contact.hpp"

Contact::Contact(void)
{
	firstname = std::string();
	lastname = std::string();
	nickname = std::string();
	phonenumber = std::string();
	darkestsecret = std::string();
}

bool	Contact::IsEmpty(void)
{
	return (firstname.empty() || lastname.empty()
		|| nickname.empty() || phonenumber.empty()
		|| darkestsecret.empty());
}

void	Contact::PrintInfo(void)
{
	std::cout << "First name: " << firstname << std::endl;
	std::cout << "Last name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phonenumber: " << phonenumber << std::endl;
	std::cout << "Darkest secret: " << darkestsecret << std::endl;
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

void	Contact::PrintListInfo(int index)
{
	std::cout << index << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right) << truncate_string(firstname, 10) << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right) << truncate_string(lastname, 10) << "|";
	std::cout << std::setw(10) << std::setiosflags(std::ios::right) << truncate_string(nickname, 10) << "|" << std::endl;
}

void	Contact::Input(void)
{
	Contact	newcontact = Contact();
	std::cout << "Enter first name: ";
	std::cin >> newcontact.firstname;
	if (std::cin.eof())
		return ;
	std::cout << "Enter last name: ";
	std::cin >> newcontact.lastname;
	if (std::cin.eof())
		return ;
	std::cout << "Enter nick name: ";
	std::cin >> newcontact.nickname;
	if (std::cin.eof())
		return ;
	std::cout << "Enter phonenumber: ";
	std::cin >> newcontact.phonenumber;
	if (std::cin.eof())
		return ;
	std::cout << "Enter your darkest secret: ";
	std::cin >> newcontact.darkestsecret;
	if (std::cin.eof())
		return ;
	if (newcontact.IsEmpty())
	{
		std::cout << "Info cannot be empty!" << std::endl;	
		return ;
	}
	*this = newcontact;
}