#include "easyfind.hpp"

template <class T>
void easyfind(T &container, int el)
{
	if (std::find(container.begin(), container.end(), el) != container.end())
		std::cout << "element " << el << " found" << std::endl;
	else
		std::cout << "element " << el << " not found" << std::endl;
}