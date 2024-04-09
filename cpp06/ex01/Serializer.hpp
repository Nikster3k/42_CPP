#ifndef SERIALIZER_H
# define SERIALIZER_H

#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer& other);
	Serializer& operator= (const Serializer& other);
	~Serializer();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif //!SERIALIZER_H
