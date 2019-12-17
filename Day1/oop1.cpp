#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person():name(""), age(0){}
	Person(string n, int a): name(n), age(a){}
	string getName() { return name; }
	void setName(string n) { name = n; }
	int getAge() { return age; }
	void setAge(int a) { age = a; }
private:
	string name;
	int age;
};


int main()
{
	Person p1("Anna", 43);
	Person p2("Bob", 34);
	cout << p1.getName() << " " << p1.getAge() << endl;
	cout << p2.getName() << " " << p2.getAge() << endl;
	return 0;
}