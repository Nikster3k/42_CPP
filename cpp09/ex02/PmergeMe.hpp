#ifndef PMERGEME_H
# define PMERGEME_H

#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

std::vector<int>					strToVector(std::string a_input);
std::vector<std::pair<int, int> >	mergeInsert(std::vector<std::pair<int, int> > a_vec);
void								PmergeMeVector(std::string a_input);
std::vector<int>					jakobInsert(std::vector<int> main, std::vector<int> pend);

#endif // !PMERGEME_H
