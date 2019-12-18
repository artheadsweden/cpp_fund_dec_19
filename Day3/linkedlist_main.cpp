#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
class Person
{
public:
	Person() :name("empty"){}
	Person(string n): name(n){}
	friend ostream& operator <<(ostream& os, const Person& other);
private:
	string name;
};

ostream& operator <<(ostream& os, const Person& other)
{
	os << other.name;
	return os;
}

int main()
{
	LinkedList<Person> mylist;
	cout << mylist.popHead() << endl;
	Person p1("Anna");
	Person p2("Peter");
	Person p3("Sue");
	mylist.insertTail(p1);
	mylist.insertTail(p2);
	mylist.insertTail(p3);
	mylist.print();
	return 0;
}