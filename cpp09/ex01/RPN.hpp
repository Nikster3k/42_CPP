#ifndef RPN_H
# define RPN_H

#include <stack>
#include <string>
#include <iostream>
#include <limits>

class RPN
{
private:
	std::stack<int>	m_calcs;
	void	addValue(char a_char);
	int		checkOverflow(long a_val);
public:
	RPN(void);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void	doRpn(const std::string& a_str);
};

#endif // !RPN_H
