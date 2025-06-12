#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.value = 1312;

	std::cout << "data address: " << &data << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "serialized: " << ptr << std::endl;
	Data *deserializedData = Serializer::deserialize(ptr);
	if (deserializedData)
		std::cout << "value value: " << deserializedData->value << std::endl;
	else
		std::cout << "deserialization failed." << std::endl;

	Data *failedDesierialization = Serializer::deserialize(0);
	if (failedDesierialization)
		std::cout << "value value: " << failedDesierialization->value << std::endl;
	else
		std::cout << "deserialization failed." << std::endl;
}
