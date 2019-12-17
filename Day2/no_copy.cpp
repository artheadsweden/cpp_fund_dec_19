#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() : name(""), age(0)
	{
		cout << "Default constructing person" << endl;
	}

	Person(string n, int a) : name(n), age(a)
	{
		cout << "Constructing " << name << endl;
	}

	Person(const Person& other) = delete;
	Person& operator =(const Person& other) = delete;


private:
	string name;
	int age;
};

int main()
{
	Person p1("Bob", 34);
	//Person p2 = p1;
	Person p3;
	//p3 = p1;

	return 0;
}