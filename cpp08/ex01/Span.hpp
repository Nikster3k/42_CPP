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
	// long				m_longspan;
	// long				m_shortspan;
	// bool				m_change;
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int a_val);
	long	shortestSpan(void);
	long	longestSpan(void);

	class SpanFull : public std::exception
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
