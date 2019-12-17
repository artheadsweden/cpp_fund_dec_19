#include <iostream>

using namespace std;

void func1(int& x)
{
	cout << "x is lvalue" << endl;
}

void func1(int&& x)
{
	cout << "x is rvalue" << endl;
}

template <typename T>
void func(T&& param)
{
	func1(forward<T>(param));
}

int main()
{
	int x = 10;
	func(x);
	func(10);
	return 0;
}