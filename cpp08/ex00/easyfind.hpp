#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <exception>
#include <algorithm>

#include <iostream>

template <typename T>
T&  easyfind(std::vector<T>& a_vec, T a_tofind)
{
	std::sort(a_vec.begin(), a_vec.end());
	typename std::vector<T>::iterator found = std::lower_bound(a_vec.begin(), a_vec.end(), a_tofind);
	if (found != a_vec.end() && *found == a_tofind)
		return (*found);
	throw (std::exception());
}

#endif //!EASYFIND_HPP
