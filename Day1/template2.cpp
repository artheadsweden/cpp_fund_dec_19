#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	decltype (5 + 6) x;
	auto result = add(2, 3);
	auto result2 = add(2.34, 5);
	return 0;
}