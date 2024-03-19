/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:07:51 by nsassenb          #+#    #+#             */
/*   Updated: 2024/03/08 09:07:52 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char ** argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) 
		{
			std::string str = std::string(argv[i]);
			for (unsigned long a = 0; a < str.length(); a++)
				str.at(a) = std::toupper(str.at(a));
			std::cout << str << (i == argc - 1 ? "\n" : " ");
		}
	}
	return (0);
}
