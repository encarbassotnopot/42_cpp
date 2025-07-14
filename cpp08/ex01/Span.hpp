#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	std::vector<int> container;
	unsigned int capacity;
	Span();

public:
	Span(unsigned int len);
	Span &operator=(const Span &other);
	Span(const Span &other);
	~Span();

	void addNumber(int num);
	void addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};