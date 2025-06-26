#include "easyfind.tpp"
#include <vector>
#include <list>

int main()
{
	int items[] = {0, 1, 2, 3, 4};
	std::vector<int> vec(items, items + 5);
	std::list<int> lst(items, items + 5);

	easyfind(vec, 2);
	easyfind(lst, 3);
}
