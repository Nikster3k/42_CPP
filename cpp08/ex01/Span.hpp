#ifndef SPAN_H
# define SPAN_H

#include <exception>
#include <limits>

class Span
{
private:
	unsigned int	m_max;
	unsigned int	m_top;
	int*			m_data;
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int a_val);
	int		shortestSpan(void);
	int		longestSpan(void);

	class SpanFullException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class SpanNotPossible : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

#endif // !SPAN_H
