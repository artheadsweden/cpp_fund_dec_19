#include <iostream>

using namespace std;

class Base
{
public:
	void nonVirtual()
	{
		cout << "Base nonVirtual called" << endl;
	}

	virtual void Virtual()
	{
		cout << "Base Virtual called" << endl;
	}
};

class Derived : public Base
{
public:
	void nonVirtual()
	{
		cout << "Derived nonVirtual called" << endl;
	}

	virtual void Virtual()
	{
		cout << "Derived Virtual called" << endl;
	}
};

int main()
{
	Base* base = new Base();
	Base* derived = new Derived();

	base->nonVirtual();
	base->Virtual();
	derived->nonVirtual();
	derived->Virtual();
	return 0;
}