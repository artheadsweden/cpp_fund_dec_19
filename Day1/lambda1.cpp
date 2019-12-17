#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 20;
	auto f = [x]() mutable{
		x++;
		cout << x << endl;
	};
	x++;
	f();
	cout << x << endl;
	return 0;
}