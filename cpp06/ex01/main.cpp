#include "Serializer.hpp"

#include <iostream>

int	main(void)
{
	Data a = Data();

	uintptr_t re = Serializer::serialize(&a);
	a.m_val = 42;
	a.m_msg = "Hello data";
	std::cout << "serialized " << re << std::endl;

	Data* b = Serializer::deserialize(re);
	std::cout << "Compare: old[ " << &a << " ], new[ " << b << " ]" << std::endl;
	std::cout << "Deserialized:" << std::endl << "Msg: \"" << b->m_msg << "\" Val1: " << b->m_val << std::endl;
	return (0);
}
