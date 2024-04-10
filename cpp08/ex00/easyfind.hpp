#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <exception>
#include <algorithm>

#include <iostream>
template <typename T>
T&  easyfind(std::vector<T> a_vec, T& a_tofind)
{
	std::cout << "Search for: " << a_tofind << std::endl;
	if (std::binary_search(a_vec.begin(), a_vec.end(), a_tofind))
		std::cout << "Found element" << std::endl;
	throw (std::exception());
}

#endif //!EASYFIND_HPP
