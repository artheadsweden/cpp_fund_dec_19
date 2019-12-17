#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyClass
{
public:
	MyClass(T v): value(v){}
	T getValue()
	{
		return value;
	}
private:
	T value;
};

int main()
{
	MyClass<int> mc1(10);
	MyClass<string> mc2("Hi there");
	cout << mc1.getValue() << endl;
	cout << mc2.getValue() << endl;
	return 0;
}