#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

#include <iostream>

template <typename T>
int  easyfind(T& container, int tofind)
{
	typename T::iterator found = std::find(container.begin(), container.end(), tofind);
	if (found != container.end())
		return (found - container.begin());
	throw (std::exception());
}

template <typename T>
int  easyfind(const T& container, int tofind)
{
	typename T::const_iterator found = std::find(container.begin(), container.end(), tofind);
	if (found != container.end())
		return (found - container.begin());
	throw (std::exception());
}

#endif //!EASYFIND_HPP
