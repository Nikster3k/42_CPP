#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T>
void	iter(T* adress, size_t size, void(*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func(adress[i]);
}

#endif // !ITER_H
