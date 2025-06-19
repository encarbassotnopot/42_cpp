#pragma once

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = b;
	b = a;
	a = temp;
}

template <typename T>
T min(T &a, T &b)
{
	return a < b ? a : b;
}

template <typename T>
T max(T &a, T &b)
{
	return a > b ? a : b;
}