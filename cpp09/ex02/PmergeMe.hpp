#ifndef PMERGEME_H
# define PMERGEME_H

#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <deque>

template <typename container = std::vector<int> >
struct Block
{
	typename container::iterator begin;
	typename container::iterator end;

	Block() : begin(), end() {}
	Block(typename container::iterator a_itBegin, typename container::iterator a_itEnd) : begin(a_itBegin), end(a_itEnd) {}

	bool operator<(const Block& other) const {return (*(this->begin) < *(other.begin));}
	bool operator>(const Block& other) const {return (*(this->begin) < *(other.begin));}

	Block&	operator+=(long step){
		this->begin += step;
		this->end += step;
		return (*this);
	}
	Block&	operator-=(long step){
		this->begin += step;
		this->end += step;
		return (*this);
	}
	inline static void	swapValues(const Block& lhs, const Block& rhs)
	{
		std::size_t iter = lhs.end - lhs.begin;

		for (std::size_t i = 0; i < iter; i++)
			std::swap(*(lhs.begin + i), *(rhs.begin + i));
	}
};



std::vector<int>					strToVector(std::string a_input);
std::vector<std::pair<int, int> >	mergeInsert(std::vector<std::pair<int, int> > a_vec);
void								PmergeMeVector(std::string a_input);
void								PmergeMeDeque(std::string a_input);
std::vector<int>					jakobInsert(std::vector<int> main, std::vector<int> pend);

#endif // !PMERGEME_H
