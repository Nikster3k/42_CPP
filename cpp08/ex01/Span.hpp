#ifndef SPAN_H
# define SPAN_H

#include <exception>
#include <limits>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int		m_max;
	std::vector<int>	m_data;
	bool				m_shortSpan;
	bool				m_longSpan;
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
