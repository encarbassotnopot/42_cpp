#include "Span.tpp"
#include <iostream>

int main(void)
{

	Span span1 = Span(5);

	span1.addNumber(6);
	span1.addNumber(3);
	span1.addNumber(17);
	span1.addNumber(9);
	span1.addNumber(11);

	std::cout << "Longest span: " << span1.longestSpan() << std::endl;
	std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;

	/////

	std::vector<int> l(10000);
	std::srand(1);
	std::generate(l.begin(), l.end(), std::rand);

	Span span2(l.size());

	span2.addNumber(l.begin(), l.end());

	std::cout << "Longest span: " << span2.longestSpan() << std::endl;
	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
}