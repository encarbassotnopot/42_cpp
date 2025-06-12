#include <stdlib.h>
#include <iostream>
#include <ctime>

class Base
{
public:
	virtual ~Base() {}
};
class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base *generate(void)
{
	std::time_t time = std::time(NULL);
	srand(time);
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "object is of type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "object is of type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "object is of type C" << std::endl;
	else
		std::cout << "object's type is unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "object is of type A" << std::endl;
		(void)a;
	}
	catch (const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "object is of type B" << std::endl;
			(void)b;
		}
		catch (const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "object is of type C" << std::endl;
				(void)c;
			}
			catch (const std::exception &e)
			{
				std::cout << "object's type is unknown" << std::endl;
			}
		}
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
