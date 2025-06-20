#pragma once
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *data;
	unsigned int len;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array<T> &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int idx) const;
	unsigned int size() const;
};