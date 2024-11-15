/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:45:02 by nsassenb          #+#    #+#             */
/*   Updated: 2024/03/22 15:30:18 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <stdlib.h>
# include <limits>
# include "Contact.hpp"

class PhoneBook 
{
private:
	Contact	contacts[8];
	int		top;
	void	add(void);
	void	search(void);
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	prompt(void);
};

#endif
