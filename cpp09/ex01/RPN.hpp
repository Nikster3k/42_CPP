#ifndef RPN_H
# define RPN_H

#include <stack>
#include <string>
#include <iostream>

class RPN
{
private:
	std::stack<int>	m_calcs;
	bool	addValue(char a_char);
public:
	RPN(void);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	bool	doRpn(const std::string& a_str);
};

#endif // !RPN_H
