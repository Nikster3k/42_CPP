#include "PmergeMe.hpp"

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

static void	printVector(const std::vector<int>& a_vec)
{
	for (std::size_t i = 0; i < a_vec.size(); ++i) 
	{
		std::cout << a_vec.at(i) << " ";
	}
	std::cout << std::endl;
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

static long	binaryInsert(std::vector<int>& a_main, int a_val, int a_maxIdx, std::size_t a_blockSize)
{
	long	start = 0;
	long	end = a_maxIdx;
	long	midpoint = 0;
	bool	isLessEqual = true;

	while (start <= end)
	{
		midpoint = (end - start) / 2 + start;
		g_comparisons++;
		isLessEqual = a_val <= a_main.at(midpoint * a_blockSize); //crashes here!!!
		if (isLessEqual)
			end = midpoint - 1;
		else
			start = midpoint + 1;
	}
	if (!isLessEqual)
		midpoint++;
	return (midpoint);
}

std::vector<int>	insertion(std::vector<int>& a_main, std::vector<int>& a_pend, std::size_t a_blockSize)
{
	std::size_t iter = 1;
	std::size_t s = 0;
	std::size_t i = 1;
	std::size_t added = 1;

	a_main.insert(a_main.begin(), a_pend.begin(), a_pend.begin() + a_blockSize);

	while (s < a_pend.size() / a_blockSize)
	{
		i = 2 * jakobsthalZahl(iter++);
		for (std::size_t x = i; x > s; --x)
		{
			if (x >= a_pend.size() / a_blockSize)
				continue;
			long index = binaryInsert(a_main, a_pend.at(x * a_blockSize), x + (added++), a_blockSize) * a_blockSize;
			a_main.insert(a_main.begin() + index, a_pend.begin() + x * a_blockSize, a_pend.begin() + x * a_blockSize + a_blockSize);
		}
		s = i;
	}
	return (a_main);
}

void	mergeInsert(std::vector<int>& a_input, std::size_t a_steps)
{
	std::size_t	blockSize = 1 << a_steps;
	std::size_t	pairSize = blockSize * 2;
	if (a_input.size() < pairSize)
		return;

	std::size_t iter = a_input.size() / pairSize;
	for (std::size_t i = 0; i < iter; i++)
	{
		++g_comparisons;
		if (a_input.at(i * pairSize) < a_input.at(i * pairSize + blockSize))
		{
			for (std::size_t x = 0; x < blockSize; x++)
				std::swap(a_input.at(i * pairSize + x), a_input.at(i * pairSize + blockSize + x));		
		}
	}
	
	mergeInsert(a_input, a_steps + 1);
	
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> tail;
	std::size_t i = 0;
	for (i = 0; i < iter; i++)
	{
		main.insert(main.end(), a_input.begin() + i * pairSize, a_input.begin() + i * pairSize + blockSize);
		pend.insert(pend.end(), a_input.begin() + i * pairSize + blockSize, a_input.begin() + i * pairSize + pairSize);
	}
	if (a_input.size() - iter * pairSize == blockSize)
		pend.insert(pend.end(), a_input.begin() + (i++) * pairSize, a_input.end());
	else
		tail.insert(tail.begin(), a_input.begin() + i * pairSize, a_input.end());
	a_input = insertion(main, pend, blockSize);
	a_input.insert(a_input.end(), tail.begin(), tail.end());
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
	
	g_comparisons = 0;
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
		<< static_cast<double>(t) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

	checker(values);

	std::cout << "Comparisons: " << g_comparisons << std::endl;
}
