#include <iostream>

using namespace std;

int main()
{
	auto ff = [](int e) {
		return [e](int b) {
			return pow(b, e);
		};
	};
	auto square = ff(2);
	auto cube = ff(3);
	cout << square(3) << endl;
	cout << square(4) << endl;
	cout << cube(3) << endl;
	cout << cube(4) << endl;
	return 0;
}