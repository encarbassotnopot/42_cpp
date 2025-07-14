#include "Span.hpp"

Span::Span(unsigned int len) : capacity(len) {}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	container = other.container;
	capacity = other.capacity;
	return *this;
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (container.size() > capacity)
		throw std::out_of_range("No space left in container");
	container.push_back(num);
}

void Span::addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd)
{
	if (container.size() > capacity)
		throw std::out_of_range("Span::addNumber: list is full");
	container.insert(container.end(), itBegin, itEnd);
}
unsigned int Span::longestSpan()
{
	if (container.size() < 2)
		throw std::length_error("Not enough elements for a span to exist");
	return max_element(container.begin(), container.end()) - min_element(container.begin(), container.end());
}

unsigned int Span::shortestSpan()
{
	int lastVal;
	unsigned int maxSpan = std::numeric_limits<unsigned int>::max();

	if (container.size() < 2)
		throw std::length_error("Not enough elements for a span to exist");

	std::sort(container.begin(), container.end());

	lastVal = *container.begin();
	for (std::vector<int>::iterator it = ++container.begin(); it != container.end(); ++it)
	{
		if (static_cast<unsigned int>(*it - lastVal) < maxSpan)
			maxSpan = *it - lastVal;
		if (maxSpan == 0)
			return maxSpan;
		lastVal = *it;
	}
	return maxSpan;
}
