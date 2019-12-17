#include <iostream>
#include <string>
using namespace std;

class MyClass
{
public:
	MyClass(string n): name(n){}
	void operator()()
	{
		cout << "I am " << name << " and I am called" << endl;
	}

private:
	string name;
};

int main()
{
	MyClass c("Anna");
	c();
	MyClass c1("Bob");
	c1();
	return 0;
}