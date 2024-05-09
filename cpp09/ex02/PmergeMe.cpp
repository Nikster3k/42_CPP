#include "PmergeMe.hpp"

#if COUNT
int g_comparisons = 0;
#endif

static std::vector<int>	strToVector(std::string a_input)
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

template <typename Container>
static void	printContainer(const Container& a_cont)
{
	for (std::size_t i = 0; i < a_cont.size(); ++i) 
	{
		std::cout << a_cont.at(i) << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
static void printSubject(const Container& a_cont)
{
	std::size_t	iter = a_cont.size() > 5 ? 4 : a_cont.size();

	for (std::size_t i = 0; i < iter; i++)
		std::cout << a_cont.at(i) << " ";
	if (iter != a_cont.size())
		std::cout << "[...]";
	std::cout << std::endl;
}

static std::vector<std::pair<Block<>, Block<> > > intVecToPair(std::vector<int>& a_input, std::size_t a_blockSize)
{
	std::vector<std::pair<Block<>, Block<> > >	pairs;
	Block<>	lhs;
	Block<>	rhs;
	std::size_t iterSize = a_input.size() / (a_blockSize * 2);
	std::size_t i = 0;
	for (; i < iterSize; ++i)
	{
		lhs.begin = a_input.begin() + i * a_blockSize * 2;
		lhs.end = lhs.begin + a_blockSize;
		rhs.begin = lhs.end;
		rhs.end = rhs.begin + a_blockSize;
#if COUNT
		g_comparisons++;
#endif
		if (lhs < rhs)
			Block<>::swapValues(lhs, rhs);
		pairs.push_back(std::make_pair(lhs, rhs));
	}
	if (i * a_blockSize * 2 + a_blockSize <= a_input.size())
	{
		lhs.begin = a_input.end();
		lhs.end = a_input.end();
		rhs.begin = a_input.begin() + i * a_blockSize * 2;
		rhs.end = rhs.begin + a_blockSize;
		pairs.push_back(std::make_pair(lhs, rhs));
	}
	return (pairs);
}

static int jakobsthalZahl(std::size_t n)
{
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

size_t	binarySearch(std::vector<Block<> >& a_main, int val, std::size_t maxIdx)
{
	size_t	low = 0;
	size_t	mid;
	bool	isLessOrEqual = false;

	while (low <= maxIdx)
	{
		mid = (low + maxIdx) / 2;
		if (mid >= a_main.size())
			return (low);
#if COUNT
		g_comparisons++;
#endif
		isLessOrEqual = val <= *(a_main.at(mid).begin);
		if (isLessOrEqual)
			maxIdx = mid - 1;
		else
			low = mid + 1;
	}
	if (!isLessOrEqual)
		mid++;
	return (mid);
}

static void    insertion(std::vector<Block<> >& a_main, std::vector<Block<> >& a_pend, std::vector<int>& a_input, std::size_t a_blockSize)
{
	std::vector<int> newInput;
	std::size_t jt_idx = 3;
	std::size_t lower = 1;
	std::size_t added = 1;
	std::size_t jacob_n = jakobsthalZahl(jt_idx);

	a_main.insert(a_main.begin(), a_pend.at(0));

	if (jacob_n >= a_pend.size()) 
			jacob_n = a_pend.size();

	while (lower < a_pend.size())
	{
		while (jacob_n > lower)
		{
			std::size_t index = binarySearch(a_main, *a_pend.at(jacob_n - 1).begin, (jacob_n - 1) + added - 1);
			a_main.insert(a_main.begin() + index, a_pend.at(jacob_n - 1));
			added++;
			jacob_n--;
		}
		lower = jakobsthalZahl(jt_idx++);
		jacob_n = jakobsthalZahl(jt_idx);
		if (jacob_n >= a_pend.size()) 
				jacob_n = a_pend.size();
	}
	newInput.reserve(a_input.size());
	for (size_t i = 0; i < a_main.size(); i++)
	{
		newInput.insert(newInput.end(), a_main.at(i).begin, a_main.at(i).end);
	}
	newInput.insert(newInput.end(), a_input.begin() + a_main.size() * a_blockSize, a_input.end());

	a_input = newInput;
}

static void	mergeInsert(std::vector<int>& a_input, std::size_t a_steps)
{
	std::size_t	blockSize = 1 << a_steps;
	if (a_input.size() < blockSize * 2)
		return;

	std::vector<std::pair<Block<> , Block<> > >	pairVect = intVecToPair(a_input, blockSize);
	mergeInsert(a_input, a_steps + 1);
	
	std::vector<Block<> > main;
	std::vector<Block<> > pend;

	for (std::size_t i = 0; i < pairVect.size(); i++)
	{
		if (pairVect.at(i).first.begin != a_input.end())
		{
			main.push_back(pairVect.at(i).first);
			pend.push_back(pairVect.at(i).second);
		}
		else
			pend.push_back(pairVect.at(i).second);
	}

	insertion(main, pend, a_input, blockSize);
}

template <typename Container>
static void checker(const Container& a_container)
{
	for (size_t i = 1; i < a_container.size(); i++) {
		if (a_container.at(i - 1) > a_container.at(i))
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

#if COUNT
	g_comparisons = 0;
#endif
	std::cout << std::setw(10) << std::left << "Before: ";
	printSubject(values);
	std::clock_t t;
	t = std::clock();
	mergeInsert(values, 0);
	t = std::clock() - t;
	std::cout << std::setw(10) << std::left << "After: ";
	printSubject(values);
	std::cout << std::fixed
		<< "Time to process a range of " << values.size() << " elements with std::vector : "
		<< t / static_cast<double>(CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
#if COUNT
	checker(values);
	std::cout << "Comparisons: " << g_comparisons << std::endl;
#endif
}


//////////////////////// DEQUE ///////////////////////////////////

static std::deque<int>	strToDeque(std::string a_input)
{
	std::deque<int>	values;
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

static std::deque<std::pair<t_qBlock, t_qBlock> > intDeqToPair(std::deque<int>& a_input, std::size_t a_blockSize)
{
	std::deque<std::pair<t_qBlock, t_qBlock > >	pairs;
	t_qBlock	lhs;
	t_qBlock	rhs;
	std::size_t iterSize = a_input.size() / (a_blockSize * 2);
	std::size_t i = 0;
	for (; i < iterSize; ++i)
	{
		lhs.begin = a_input.begin() + i * a_blockSize * 2;
		lhs.end = lhs.begin + a_blockSize;
		rhs.begin = lhs.end;
		rhs.end = rhs.begin + a_blockSize;
#if COUNT
		g_comparisons++;
#endif
		if (lhs < rhs)
			t_qBlock::swapValues(lhs, rhs);
		pairs.push_back(std::make_pair(lhs, rhs));
	}
	if (i * a_blockSize * 2 + a_blockSize <= a_input.size())
	{
		lhs.begin = a_input.end();
		lhs.end = a_input.end();
		rhs.begin = a_input.begin() + i * a_blockSize * 2;
		rhs.end = rhs.begin + a_blockSize;
		pairs.push_back(std::make_pair(lhs, rhs));
	}
	return (pairs);
}

static size_t	binarySearchDeque(std::deque<t_qBlock>& a_main, int val, std::size_t maxIdx)
{
	size_t	low = 0;
	size_t	mid;
	bool	isLessOrEqual = false;

	while (low <= maxIdx)
	{
		mid = (low + maxIdx) / 2;
		if (mid >= a_main.size())
			return (low);
#if COUNT
		g_comparisons++;
#endif
		isLessOrEqual = val <= *(a_main.at(mid).begin);
		if (isLessOrEqual)
			maxIdx = mid - 1;
		else
			low = mid + 1;
	}
	if (!isLessOrEqual)
		mid++;
	return (mid);
}

static void	insertionDeque(std::deque<t_qBlock >& a_main, std::deque<t_qBlock >& a_pend, std::deque<int>& a_input, std::size_t a_blockSize)
{
	std::deque<int> newInput;
	std::size_t jt_idx = 3;
	std::size_t lower = 1;
	std::size_t added = 1;
	std::size_t jacob_n = jakobsthalZahl(jt_idx);

	a_main.insert(a_main.begin(), a_pend.at(0));

	if (jacob_n >= a_pend.size()) 
			jacob_n = a_pend.size();

	while (lower < a_pend.size())
	{
		while (jacob_n > lower)
		{
			std::size_t index = binarySearchDeque(a_main, *a_pend.at(jacob_n - 1).begin, (jacob_n - 1) + added - 1);
			a_main.insert(a_main.begin() + index, a_pend.at(jacob_n - 1));
			added++;
			jacob_n--;
		}
		lower = jakobsthalZahl(jt_idx++);
		jacob_n = jakobsthalZahl(jt_idx);
		if (jacob_n >= a_pend.size()) 
				jacob_n = a_pend.size();
	}
	for (size_t i = 0; i < a_main.size(); i++)
	{
		newInput.insert(newInput.end(), a_main.at(i).begin, a_main.at(i).end);
	}
	newInput.insert(newInput.end(), a_input.begin() + a_main.size() * a_blockSize, a_input.end());

	a_input = newInput;
}

static void	mergeInsertDeque(std::deque<int>& a_input, std::size_t a_steps)
{
	std::size_t	blockSize = 1 << a_steps;
	if (a_input.size() < blockSize * 2)
		return;

	std::deque<std::pair<t_qBlock , t_qBlock > > pairVect = intDeqToPair(a_input, blockSize);
	mergeInsertDeque(a_input, a_steps + 1);
	
	std::deque<t_qBlock > main;
	std::deque<t_qBlock > pend;

	for (std::size_t i = 0; i < pairVect.size(); i++)
	{
		if (pairVect.at(i).first.begin != a_input.end())
		{
			main.push_back(pairVect.at(i).first);
			pend.push_back(pairVect.at(i).second);
		}
		else
			pend.push_back(pairVect.at(i).second);
	}

	insertionDeque(main, pend, a_input, blockSize);
}

void	PmergeMeDeque(std::string a_input)
{
	std::deque<int>	values = strToDeque(a_input);
	
#if COUNT
	g_comparisons = 0;
#endif
	std::clock_t t;
	t = std::clock();
	mergeInsertDeque(values, 0);
	t = std::clock() - t;
	std::cout << std::fixed
		<< "Time to process a range of " << values.size() << " elements with std::deque : "
		<< t / static_cast<double>(CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
#if COUNT
	checker(values);
	std::cout << "Comparisons: " << g_comparisons << std::endl;
#endif
}
