#include "PmergeMe.hpp"
#include <cstddef>
#include <iterator>
#include <limits>
#include <stdexcept>

#define DEBUG 1

int g_comparisons = 0;

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
		std::size_t num_pos = a_input.find_first_of("0123456789");
		std::size_t space_pos;
		long		value;
		if (num_pos == std::string::npos)
			break ;
		space_pos = a_input.find_first_of(" ", num_pos);
		space_pos = space_pos == std::string::npos ? a_input.length() - 1 : space_pos;
		value = std::strtol(a_input.substr(num_pos).c_str(), NULL, 10);
		if (value < 0 && value > std::numeric_limits<int>::max())
			throw (std::runtime_error("Error: number too big."));
		values.push_back(value);
		a_input.erase(0, space_pos);
	}
	return (values);
}

static void	printPairVector(const std::vector<std::pair<int, int> >& a_vec)
{
	for (std::size_t i = 0; i < a_vec.size(); ++i) 
	{
		std::cout << "(" << a_vec.at(i).first << ", " << a_vec.at(i).second << "), ";
	}
	std::cout << std::endl;
}

static void	printVector(const std::vector<int>& a_vec)
{
	for (std::size_t i = 0; i < a_vec.size(); ++i) 
	{
		std::cout << a_vec.at(i) << ", ";
	}
	std::cout << std::endl;
}

std::vector<std::pair<int, int> >	mergeInsert(std::vector<std::pair<int, int> > a_vec)
{
	if (a_vec.size() == 1)
		return (a_vec);
	std::vector<std::pair<int, int> > merged;
	std::vector<std::pair<int, int> > lhs = mergeInsert(std::vector<std::pair<int, int> >(a_vec.begin(), a_vec.begin() + a_vec.size() / 2));
	std::vector<std::pair<int, int> > rhs = mergeInsert(std::vector<std::pair<int, int> >(a_vec.begin() + a_vec.size() / 2, a_vec.end()));
	while (lhs.size() != 0 && rhs.size() != 0)
	{
		if (lhs.front().second <= rhs.front().second)
		{
			merged.push_back(lhs.front());
			lhs.erase(lhs.begin());
		}
		else
		{
			merged.push_back(rhs.front());
			rhs.erase(rhs.begin());
		}
		g_comparisons++;
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
	return (merged);
}

static std::vector<std::pair<int, int> > intVecToPair(std::vector<int> a_vec)
{
	std::vector<std::pair<int, int> >	pairs;

	for (std::size_t i = 0; i < a_vec.size(); ++i)
	{
		std::pair<int, int> pair;
		pair.first = a_vec.at(i);
		++i;
		if (i < a_vec.size())
			pair.second = a_vec.at(i);
		else
			pair.second = -1;
		if (pair.first > pair.second)
			std::swap(pair.first, pair.second);
		pairs.push_back(pair);
	}
	return (pairs);
}

static int jakobsthalZahl(std::size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (2 * jakobsthalZahl(n - 2) + jakobsthalZahl(n - 1));
}

static void	binaryInsert(std::vector<int>& a_vec, int val)
{
	std::size_t start = 0;
	std::size_t end = a_vec.size();
	std::size_t	midpoint = end / 2;
	
	while (midpoint != start || midpoint != end)
	{
		midpoint = (end - start) / 2 + start;
		if (val <= a_vec.at(midpoint))
			end = midpoint;
		else
			start = midpoint;
	}
	a_vec.insert(a_vec.begin() + midpoint, val);
}

std::vector<int>	jakobInsert(std::vector<int> main, std::vector<int> pend)
{
	std::vector<int> sorted;

	// main.insert(main.begin(), pend.front());
	// pend.erase(pend.begin());

	std::cout << "Main: ";
	printVector(main);
	std::cout << "Pend: ";
	printVector(pend);

	// std::size_t iter = 1;
	// std::size_t s = 0;
	// std::size_t i = 0;
	while (!pend.empty())
	{
		jakobsthalZahl(1);
		binaryInsert(main, pend.front());
		pend.erase(pend.begin());
	}

	std::cout << "Main: ";
	printVector(main);
	std::cout << "Pend: ";
	printVector(pend);

	return (sorted);
}

void	PmergeMeVector(std::string a_input)
{
	std::vector<int>	values = strToVector(a_input);
	std::vector<std::pair<int, int> > pairs = intVecToPair(values);
	pairs = mergeInsert(pairs);
	printPairVector(pairs);
	std::vector<int> main;
	std::vector<int> pend;
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs.at(i).first == -1)
		{
			pend.push_back(pairs.at(i).second);
		}
		else
		{
			main.push_back(pairs.at(i).second);
			pend.push_back(pairs.at(i).first);
		}
	}
	jakobInsert(main, pend);
	std::cout << "Comparisons: " << g_comparisons << std::endl;
}
