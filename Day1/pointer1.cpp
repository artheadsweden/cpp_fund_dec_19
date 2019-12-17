#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int* iptr = &x;
	*iptr++;
	cout << x << " " << *iptr << endl;

	return 0;
}