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

// template <template <typename, typename> class Container, typename Alloc>
// int  easyfind(Container<int, Alloc>& a_container, int tofind)
// {
// 	typename Container<int, Alloc>::iterator found = std::find(a_container.begin(), a_container.end(), tofind);
// 	if (found != a_container.end())
// 		return (found - a_container.begin());
// 	throw (std::exception());
// }

// template <template <typename, typename> class Container, typename Alloc>
// int  easyfind(const Container<int, Alloc>& a_container, int tofind)
// {
// 	typename Container<int, Alloc>::const_iterator found = std::find(a_container.begin(), a_container.end(), tofind);
// 	if (found != a_container.end())
// 		return (found - a_container.begin());
// 	throw (std::exception());
// }

#endif //!EASYFIND_HPP
