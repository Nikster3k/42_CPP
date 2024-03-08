/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:45:05 by nsassenb          #+#    #+#             */
/*   Updated: 2024/03/07 14:46:03 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact 
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string	phonenumber;
	std::string	darkestSecret;

public:
	Contact(void);
	~Contact(void);
	void input(void);
	bool isEmpty(void);
	void printInfo(void);
	void printListInfo(int index);
};

#endif
