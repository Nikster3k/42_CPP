#ifndef PMERGEME_H
# define PMERGEME_H

#define COUNT 0

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cmath>

template <typename container = std::vector<int> >
struct Block
{
	typename container::iterator begin;
	typename container::iterator end;

	Block() : begin(), end() {}
	Block(typename container::iterator a_itBegin, typename container::iterator a_itEnd) : begin(a_itBegin), end(a_itEnd) {}

	bool operator<(const Block& other) const {return (*(this->begin) < *(other.begin));}
	bool operator>(const Block& other) const {return (*(this->begin) < *(other.begin));}
	inline static void	swapValues(const Block& lhs, const Block& rhs)
	{
		std::size_t iter = lhs.end - lhs.begin;

		for (std::size_t i = 0; i < iter; i++)
			std::swap(*(lhs.begin + i), *(rhs.begin + i));
	}
};

typedef Block<std::deque<int> > t_qBlock;

void								PmergeMeVector(std::string a_input);
void								PmergeMeDeque(std::string a_input);

#endif // !PMERGEME_H
