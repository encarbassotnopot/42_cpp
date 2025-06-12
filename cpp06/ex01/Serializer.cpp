#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	if (ptr)
		return reinterpret_cast<uintptr_t>(ptr);
	return uintptr_t(NULL);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	if (raw != 0)
		return reinterpret_cast<Data *>(raw);
	return NULL;
}
