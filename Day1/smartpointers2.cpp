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
	shared_ptr<MyClass> shared2;
	{
		auto shared1 = make_shared<MyClass>();
		shared2 = shared1;
		MyClass mc;
	}
	auto xptr = make_unique<int>(10);

	cout << xptr << endl;
	cout << "After scope" << endl;
	return 0;
}