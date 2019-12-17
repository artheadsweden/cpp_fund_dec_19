#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass(): value(0)
	{
		cout << "Default constructor" << endl;
	}

	MyClass(int v) : value(v)
	{
		cout << "Constructor with argument " << value << endl;
	}

	MyClass(const MyClass& other) : value(other.value)
	{
		cout << "Copy constructor with value " << value << endl;
	}

	MyClass(MyClass&& other) noexcept : value(other.value)
	{
		cout << "Move constructor with value " << value << endl;
	}

	MyClass& operator =(const MyClass& other)
	{
		value = other.value;
		cout << "Copy assignment operator with value " << value << endl;
		return *this;
	}

	MyClass& operator =(MyClass&& other) noexcept
	{
		value = other.value;
		cout << "Move assignment operator with value " << value << endl;
		return *this;
	}
private:
	int value;
};

int main()
{
	int x = 10;
	MyClass mc1;
	MyClass mc2(x);
	MyClass mc3 = mc2;
	mc1 = mc2;
	return 0;
}