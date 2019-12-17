#include <iostream>

using namespace std;

auto func_fact(int e)
{
	return [e](int b)
	{
		return pow(b, e);
	};
}

int main()
{
	auto f = func_fact(2);
	auto result = f(3);
	return 0;
}