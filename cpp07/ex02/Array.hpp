#ifndef ARRAY_H
# define ARRAY_H

#include <exception>
#include <stddef.h>

template <typename T>
class Array
{
private:
	T*				m_data;
	unsigned int	m_size;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	unsigned int	size(void) const;
	T&				operator[] (unsigned int n);
};


template <typename T>
Array<T>::Array(void)
{
	m_data = NULL;
	m_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	m_data = new T[n];
	m_size = n;
	for (std::size_t i = 0; i < m_size; i++)
	{
		m_data[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& other)
{
	m_data = new T[other.m_size];
	m_size = other.m_size;
	for (std::size_t i = 0; i < m_size; i++)
	{
		m_data[i] = T(other.m_data[i]);
	}
}

template <typename T>
Array<T>& Array<T>::operator= (const Array& other)
{
	if (this != &other)
	{
		delete[] m_data;
		m_data = new T[other.m_size];
		m_size = other.m_size;
		for (std::size_t i = 0; i < m_size; i++)
		{
			m_data[i] = T(other.m_data[i]);
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_data;
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (m_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= m_size)
		throw(std::exception());
	return (m_data[n]);
}

#endif // !ARRAY_H
