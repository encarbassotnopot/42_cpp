#pragma once
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *data;
	unsigned int len;

public:
	Array() : data(new T()), len(0) {}

	Array(unsigned int n) : data(new T[n]), len(n) {}

	Array(const Array &other)
	{
		*this = other;
	}

	Array<T> &operator=(const Array &other)
	{
		if (this == &other)
			return *this;
		for (unsigned int i = 0; i < len; i++)
			data[i] = other[i];
		return *this;
	}

	~Array()
	{
		delete[] data;
	}

	T &operator[](unsigned int idx) const
	{
		if (idx >= len)
			throw std::out_of_range("index out of bounds");
		return data[idx];
	}

	unsigned int size() const
	{
		return len;
	}
};
