#include <iostream>

using namespace std;

int main()
{
	int* iptr = new int(10);
	int x = 12;
	delete iptr;
	iptr = &x;
	//delete iptr;
	return 0;
}