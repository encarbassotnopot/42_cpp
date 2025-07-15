#pragma once
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:
public:
    MutantStack();
    ~MutantStack();
    MutantStack &operator=(const MutantStack &other);
    MutantStack(const MutantStack &other);

    typedef typename Container::iterator iterator;
    iterator begin();
    iterator end();
};