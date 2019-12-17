#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int* iptr = &x;
	
	int** iptrptr = &iptr;
	const int const* const* const* iptrptrptr = &iptrptr;
	cout << x << " " << *iptr << " " << **iptrptr << " " << ***iptrptrptr << endl;
	return 0;
}