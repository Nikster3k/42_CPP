#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>

template <typename T = int>
class MutantStack : public std::stack<T>
{
public:
	struct iterator
	{
	private:
		T*	m_ptr;
		iterator(void);
	public:
		iterator(T* a_ptr);
		iterator(const iterator& other);
		iterator& operator=(const iterator& other);
		~iterator();

		iterator&	operator++();
		iterator	operator++(int);
		iterator&	operator--();
		iterator	operator--(int);
		T&			operator*()	const;
		T*			operator->() const;
		bool		operator==(const iterator& other) const;
		bool		operator!=(const iterator& other) const;
	};

	MutantStack(void);
	MutantStack(const MutantStack<T>& other);
	MutantStack<T>& operator=(const MutantStack<T>& other);
	~MutantStack();

	MutantStack<T>::iterator	begin(void);
	MutantStack<T>::iterator	end(void);
};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator= (const MutantStack<T>& other)
{
	if (this != &other)
	{
		std::stack<T>	tmp(other);
		this->c.swap(tmp.c);
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (MutantStack<T>::iterator(&this->c[0]));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (MutantStack<T>::iterator(&this->c[this->size()]));
}

template <typename T>
MutantStack<T>::iterator::iterator(T* a_ptr) : m_ptr(a_ptr) {}

template <typename T>
MutantStack<T>::iterator::iterator(const MutantStack<T>::iterator& other) : m_ptr(other.m_ptr) {}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const MutantStack<T>::iterator& other)
{
	if (this != &other)
	{
		m_ptr = other.m_ptr;
	}
	return (*this);
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++()
{
	++m_ptr;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
	MutantStack<T>::iterator tmp = *this;
	++(*this);
	return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--()
{
	--m_ptr;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
	MutantStack<T>::iterator tmp = *this;
	--(*this);
	return (tmp);
}

template <typename T>
T& MutantStack<T>::iterator::operator*() const
{
	return (*m_ptr);
}

template <typename T>
T* MutantStack<T>::iterator::operator->() const
{
	return (m_ptr);
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator &other) const
{
	return (this->m_ptr == other.m_ptr);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &other) const
{
	return (this->m_ptr != other.m_ptr);
}

#endif // !MUTANTSTACK_H
