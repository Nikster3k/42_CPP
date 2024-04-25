#include "PmergeMe.hpp"


int g_comparisons = 0;

Block::Block() : begin(), end() {}

Block::Block(std::vector<int>::iterator a_itBegin, std::vector<int>::iterator a_itEnd) : begin(a_itBegin), end(a_itEnd) {}

bool	Block::operator<(const Block& other) const
{
	return (*(this->begin) < *(other.begin));
}

bool	Block::operator>(const Block& other) const
{
	return (*(this->begin) < *(other.begin));
}

inline void Block::swapValues(const Block& lhs, const Block& rhs)
{
	std::size_t iter = lhs.end - lhs.begin;

	for (std::size_t i = 0; i < iter; i++)
		std::swap(*(lhs.begin + i), *(rhs.begin + i));
}

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

static void	printVector(const std::vector<int>& a_vec)
{
	for (std::size_t i = 0; i < a_vec.size(); ++i) 
	{
		std::cout << a_vec.at(i) << " ";
	}
	std::cout << std::endl;
}

static std::vector<std::pair<Block, Block> > intVecToPair(std::vector<int>& a_vec, std::size_t a_blockSize)
{
	std::vector<std::pair<Block, Block> >	pairs;
	Block	lhs;
	Block	rhs;
	std::size_t iterSize = a_vec.size() / (a_blockSize * 2);
	for (std::size_t i = 0; i < iterSize; ++i)
	{
		lhs.begin = a_vec.begin() + i * a_blockSize * 2;
		lhs.end = lhs.begin + a_blockSize;
		rhs.begin = lhs.end;
		rhs.end = rhs.begin + a_blockSize;
		g_comparisons++;
		if (lhs < rhs)
			Block::swapValues(lhs, rhs);
		pairs.push_back(std::make_pair(lhs, rhs));
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

static long	binaryInsert(std::vector<Block>& a_main, int val, int maxIdx)
{
	long	start = 0;
	long	end = maxIdx;
	long	midpoint = 0;
	bool	isLessEqual;
	
	while (start <= end)
	{
		midpoint = (end - start) / 2 + start;
		g_comparisons++;
		isLessEqual = val <= *a_main.at(midpoint).begin;
		if (isLessEqual)
			end = midpoint - 1;
		else
			start = midpoint + 1;
	}
	if (!isLessEqual)
		midpoint++;
	return (midpoint);
}

void	insertion(std::vector<Block>& a_main, std::vector<Block>& a_pend, std::vector<int>& a_input, std::size_t a_blockSize)
{
	std::vector<int> sorted;
	std::size_t iter = 1;
	std::size_t s = 0;
	std::size_t i = 1;
	std::size_t added = 0;

	a_main.insert(a_main.begin(), a_pend.front());

	while (s < a_pend.size())
	{
		i = 2 * jakobsthalZahl(iter++);
		for (std::size_t x = i; x > s; --x)
		{
			if (x >= a_pend.size())
				continue;
			long index = binaryInsert(a_main, *a_pend.at(x).begin, x + (added++));
			a_main.insert(a_main.begin() + index, a_pend.at(x));
		}
		s = i;
	}
	for (std::size_t i = 0; i < a_main.size(); i++)
	{
		sorted.insert(sorted.end(), a_main.at(i).begin, a_main.at(i).end);
	}
	sorted.insert(sorted.end(), a_input.begin() + a_main.size() * a_blockSize, a_input.end());
	a_input = sorted;
}

void	mergeInsert(std::vector<int>& a_input, std::size_t a_steps)
{
	std::size_t	blockSize = 1 << a_steps;
	if (a_input.size() < blockSize * 2)
		return;

	std::vector<std::pair<Block, Block> >	pairVect = intVecToPair(a_input, blockSize);
	mergeInsert(a_input, a_steps + 1);
	
	std::vector<Block> main;
	std::vector<Block> pend;

	std::size_t	iter = a_input.size() / (blockSize << 1);
	if (iter != 1 && iter % 2)
		iter--;
	std::size_t i = 0;
	for (; i < iter; i++)
	{
		main.push_back(pairVect.at(i).first);
		pend.push_back(pairVect.at(i).second);
	}
	for (; i < pairVect.size(); i++)
	{
		pend.push_back(pairVect.at(i).first);
		pend.push_back(pairVect.at(i).second);
	}
	if (blockSize == 1 && a_input.size() % 2)
		pend.push_back(Block(a_input.end() - 1, a_input.end()));
	insertion(main, pend, a_input, blockSize);
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



void	PmergeMeVector(std::string a_input)
{
	std::vector<int>	values = strToVector(a_input);
	
	std::cout << "Before: ";
	printVector(values);
	std::clock_t t;
	t = std::clock();
	mergeInsert(values, 0);
	t = std::clock() - t;
	std::cout << "After: ";
	printVector(values);
	std::cout << std::fixed
		<< "Time to process a range of " << values.size() << " elements with std::vector : "
		<< static_cast<float>(t) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

	checker(values);

	std::cout << "Comparisons: " << g_comparisons << std::endl;
}
