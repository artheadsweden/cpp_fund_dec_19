#include <iostream>

using namespace std;

int main()
{
	auto f = [x = 0]()mutable{
		x++;
		return x;
	};
	cout << f() << endl;
	cout << f() << endl;

	return 0;
}