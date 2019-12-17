#include <iostream>
#include <vector>

using namespace std;

class MyClass
{
public:
	MyClass() : value(nullptr)
	{
		cout << "Default constructor" << endl;
	}

	MyClass(int v) : value(new int(v))
	{
		cout << "Constructor with argument " << *value << endl;
	}

	MyClass(const MyClass& other)
	{
		if (other.value)
		{
			value = new int(*other.value);
			cout << "Copy constructor with value " << *value << endl;
		}
		else
		{
			cout << "Copy constructor with value nullptr" << endl;
			value = nullptr;
		}
	}
	
	MyClass(MyClass&& other) noexcept : value(nullptr)
	{
		swap(value, other.value);
		if (value)
		{
			cout << "Move constructor with value " << *value << endl;
		}
		else
		{
			cout << "Move constructor with value nullptr" << endl;
		}
	}
	
	~MyClass()
	{
		if (value)
		{
			cout << "Destructing object with value " << *value << endl;
			delete value;
		}
		else
		{
			cout << "Destructing object with value nullptr" << endl;

		}
	}

	MyClass& operator =(const MyClass& other)
	{
		if (other.value)
		{
			value = new int(*other.value);
			cout << "Copy assignment operator with value " << *value << endl;
		}
		else
		{
			cout << "Copy assignment operator with value nullptr" << endl;
			value = nullptr;
		}

		return *this;
	}
	
	MyClass& operator =(MyClass&& other) noexcept
	{
		value = nullptr;
		swap(value, other.value);
		if (value)
		{
			cout << "Move assignment operator with value " << *value << endl;
		}
		else
		{
			cout << "Move assignment operator with value nullptr" << endl;
		}
		return *this;
	}
	

	void setValue(int i)
	{
		if (value)
		{
			delete value;
		}
		value = new int(i);
	}
private:
	int* value;
};

int main()
{
	vector<MyClass> values;
	for (int i = 0; i < 100; i++)
	{
		MyClass obj(i);
		values.push_back(obj);
	}
	return 0;
}