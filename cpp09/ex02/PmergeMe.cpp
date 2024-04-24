#include "PmergeMe.hpp"
#include <cstddef>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>


int g_comparisons = 0;

std::vector<int>	strToVector(std::string a_input)
{
	std::vector<int>	values;
	if (a_input.find_first_not_of("0123456789 ") != std::string::npos)
		throw(std::runtime_error("Error: invalid characters in input."));
	while (a_input.size() > 0)
	{
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

// static void	printPairVector(const std::vector<std::pair<int, int> >& a_vec)
// {
// 	for (std::size_t i = 0; i < a_vec.size(); ++i) 
// 	{
// 		std::cout << "(" << a_vec.at(i).first << ", " << a_vec.at(i).second << "), ";
// 	}
// 	std::cout << std::endl;
// }

// static void	printVector(const std::vector<int>& a_vec)
// {
// 	for (std::size_t i = 0; i < a_vec.size(); ++i) 
// 	{
// 		std::cout << a_vec.at(i) << ", ";
// 	}
// 	std::cout << std::endl;
// }

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
		g_comparisons++;
		if (pair.first > pair.second)
			std::swap(pair.first, pair.second);
		pairs.push_back(pair);
	}
	return (pairs);
}

static int jakobsthalZahl(std::size_t n)
{
	std::size_t n2 = 0;
	std::size_t n1 = 1;
	std::size_t result = 0;

	std::size_t i = 1;
	while (i < n)
	{
		result = 2 * n2 + n1;
		n1 = n2;
		n2 = result;
		i++;
	}
	return (result);
}

static void	binaryInsert(std::vector<int>& a_vec, int val, int maxIdx)
{
	long	start = 0;
	long	end = maxIdx;
	long	midpoint = 0;
	
	while (start <= end)
	{
		midpoint = (end - start) / 2 + start;
		g_comparisons++;
		if (val <= a_vec.at(midpoint))
			end = midpoint - 1;
		else
			start = midpoint + 1;
	}
	g_comparisons++;
	if (val >= a_vec.at(midpoint))
		midpoint++;
	a_vec.insert(a_vec.begin() + midpoint, val);
}

static void checker(const std::vector<int>& vector)
{
	for (size_t i = 1; i < vector.size(); i++) {
		if (vector.at(i - 1) > vector.at(i))
		{
			std::cout << "Bad" << std::endl;
			return;
		}
	}
	std::cout << "Good" << std::endl;
}

std::vector<int>	jakobInsert(std::vector<int> main, std::vector<int> pend)
{
	std::vector<int> sorted;

	main.insert(main.begin(), pend.front());

	// std::cout << "Main: ";
	// printVector(main);
	// std::cout << "Pend: ";
	// printVector(pend);

	std::size_t iter = 1;
	std::size_t s = 0;
	std::size_t i = 1;
	std::size_t added = 0;
	while (s < pend.size())
	{
		i = 2 * jakobsthalZahl(iter++);
		for (std::size_t x = i; x > s; --x)
		{
			if (x >= pend.size())
				continue;
			binaryInsert(main, pend.at(x), x + (added++));
		}
		s = i;
	}

	std::cout << "Main Sorted: ";
	// printVector(main);
	checker(main);

	return (sorted);
}

void	PmergeMeVector(std::string a_input)
{
	std::vector<int>	values = strToVector(a_input);
	std::vector<std::pair<int, int> > pairs = intVecToPair(values);
	std::cout << "jaco = " << jakobsthalZahl(5) << std::endl;
	pairs = mergeInsert(pairs);
	// printPairVector(pairs);
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
