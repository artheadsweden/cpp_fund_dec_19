#include <iostream>


using namespace std;
/*
void func(int&& value)
{
	cout << "Value is rvalue" << endl;
}*/

void func(int& value)
{
	cout << "Value is lvalue" << endl;
}

int main()
{
	int x = 10;
	func(x);
	
	return 0;
}
