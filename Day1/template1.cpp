#include <iostream>
#include <string>
using namespace std;

/*
int max(int a, int b)
{
	return a > b ? a : b;
}

double max(double a, double b)
{
	return a > b ? a : b;
}

string max(string a, string b)
{
	return a > b ? a : b;
}
*/

template <typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}


int main()
{
	int i1 = 4;
	int i2 = 5;
	cout << "max(4, 5) = " << max(i1, i2) << endl;
	double d1 = 4.56;
	double d2 = 7.45;
	cout << "max(4.56, 7.45) = " << max(d1, d2) << endl;
	string s1 = "Hello";
	string s2 = "World";
	cout << "max(Hello, World) = " << max(s1, s2) << endl;
	return 0;
}