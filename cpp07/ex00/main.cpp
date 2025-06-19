#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 0;
	int b = 1;
	swap<int>(a, b);

	std::cout << "a: " << a << " b: " << b << std::endl;

	a = 12;
	b = 15;
	std::cout << "a: " << a << " b: " << b << " smallest value is " << min<int>(a, b)
			  << std::endl;
	std::cout << "a: " << a << " b: " << b << " largest value is " << max<int>(a, b)
			  << std::endl;
}
