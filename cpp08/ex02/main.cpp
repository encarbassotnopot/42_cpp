#include "MutantStack.tpp"
#include <iostream>
#include <vector>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	/////

	std::vector<int> nonMutantVec;
	nonMutantVec.push_back(5);
	nonMutantVec.push_back(17);
	std::cout << nonMutantVec.back() << std::endl;
	nonMutantVec.pop_back();
	std::cout << nonMutantVec.size() << std::endl;
	nonMutantVec.push_back(3);
	nonMutantVec.push_back(5);
	nonMutantVec.push_back(737);
	nonMutantVec.push_back(0);
	std::vector<int>::iterator v_it = nonMutantVec.begin();
	std::vector<int>::iterator v_ite = nonMutantVec.end();
	++it;
	--it;
	while (v_it != v_ite)
	{
		std::cout << *v_it << std::endl;
		++v_it;
	}
	std::vector<int> v(nonMutantVec);
	return 0;
}