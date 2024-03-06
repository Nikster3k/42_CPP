/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:45:05 by nsassenb          #+#    #+#             */
/*   Updated: 2024/03/06 18:26:35 by nsassenb         ###   ########.fr       */
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
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string	phonenumber;
	std::string	darkestsecret;

public:
	Contact(void);
	void Input(void);
	bool IsEmpty(void);
	void PrintInfo(void);
	void PrintListInfo(int index);
};

#endif