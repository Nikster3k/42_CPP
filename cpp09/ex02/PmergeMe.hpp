#ifndef PMERGEME_H
# define PMERGEME_H

#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

struct Block
{
	std::vector<int>::iterator begin;
	std::vector<int>::iterator end;

	bool operator<(const Block& other) const;
	bool operator>(const Block& other) const;
	inline static void	swapValues(const Block& lhs, const Block& rhs);
};



std::vector<int>					strToVector(std::string a_input);
std::vector<std::pair<int, int> >	mergeInsert(std::vector<std::pair<int, int> > a_vec);
void								PmergeMeVector(std::string a_input);
std::vector<int>					jakobInsert(std::vector<int> main, std::vector<int> pend);

#endif // !PMERGEME_H
