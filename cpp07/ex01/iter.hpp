#pragma once
#include <iostream>

template <typename T>
// això no es pot fer amb c++98, només a partir de c++20:
// void iter(T (&array)[], size_t len, void (*func)(T &))
void iter(T *array, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void print(T &i)
{
	std::cout << i << std::endl;
}
