#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& lhs, T& rhs)
{
	T	temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename T>
T&	min(T& lhs, T& rhs)
{
	return (rhs <= lhs ? rhs : lhs);
}

template <typename T>
T&	max(T& lhs, T&rhs)
{
	return (rhs >= lhs ? rhs : lhs);
}

#endif //!WHATEVER_HPP
