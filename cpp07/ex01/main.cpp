#include "iter.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	iter<int>(arr, 5, print<int>);
}
