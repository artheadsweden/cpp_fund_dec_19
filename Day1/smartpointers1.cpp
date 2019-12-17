#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
public:
	MyClass()
	{
		cout << "Constructor" << endl;
	}

	~MyClass()
	{
		cout << "Destructor" << endl;
	}
};


int main()
{
	auto mcPtr = make_unique<MyClass>();
	unique_ptr<MyClass> mcPtr2 = move(mcPtr);
	mcPtr = nullptr;
	
	
	return 0;
}