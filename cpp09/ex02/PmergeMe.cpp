#include "PmergeMe.hpp"
#include <stdexcept>

#define DEBUG 0

std::vector<int>	strToVector(std::string a_input)
{
	std::vector<int>	values;
	if (a_input.find_first_not_of("0123456789 ") != std::string::npos)
		throw(std::runtime_error("Error: invalid characters in input."));
	while (a_input.size() > 0)
	{
#if DEBUG
		std::cout << a_input << std::endl;
#endif
		long value = std::strtol(a_input.c_str(), NULL, 10);
		if (value < 0 || value > std::numeric_limits<unsigned int>().max())
			throw (std::runtime_error("Error: number too big."));
		values.push_back(value);
		std::size_t	space_pos = a_input.find(" ");
		space_pos = space_pos == std::string::npos ? a_input.length() - 1 : space_pos;
		a_input.erase(0, space_pos + 1);
	}
	return (values);
}

static void	printVector(const std::vector<int>& a_vec)
{
	for (std::size_t i = 0; i < a_vec.size(); ++i) 
	{
		std::cout << a_vec.at(i) << ", ";
	}
	std::cout << std::endl;
}

std::vector<int>	mergeInsert(std::vector<int> a_vec)
{
	// printVector(a_vec);
	if (a_vec.size() == 1)
	{
		// printVector(a_vec);
		return (a_vec);
	}
	std::vector<int> merged;
	std::vector<int> lhs = mergeInsert(std::vector<int>(a_vec.begin(), a_vec.begin() + a_vec.size() / 2));
	std::vector<int> rhs = mergeInsert(std::vector<int>(a_vec.begin() + a_vec.size() / 2, a_vec.end()));
#if DEBUG
	std::cout << "lhs: "; 
	printVector(lhs);
	std::cout << "rhs: "; 
	printVector(rhs);
#endif
	while (lhs.size() != 0 && rhs.size() != 0)
	{
#if DEBUG
		std::cout << lhs.front() << " <= " << rhs.front() << std::endl;
#endif
		if (lhs.front() <= rhs.front())
		{
			merged.push_back(lhs.front());
			lhs.erase(lhs.begin());
		}
		else
		{
			merged.push_back(rhs.front());
			rhs.erase(rhs.begin());
		}
	}
	while (lhs.size() > 0)
	{
		merged.push_back(lhs.front());
		lhs.erase(lhs.begin());
	}
	while (rhs.size() > 0)
	{
		merged.push_back(rhs.front());
		rhs.erase(rhs.begin());
	}
#if DEBUG
	std::cout << "Merged: ";
	printVector(merged);
#endif
	return (merged);
}

void	PmergeMeVector(std::string a_input)
{
	std::vector<int>	values = strToVector(a_input);
	values = mergeInsert(values);
	printVector(values);
}
