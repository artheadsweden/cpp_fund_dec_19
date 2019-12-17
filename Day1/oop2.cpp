#include <iostream>

using namespace std;

class Value
{
public:
	explicit Value(int v): value(v){}
	int getValue() { return value; }
private:
	int value;
};

int main()
{
	Value v1(34);
	cout << v1.getValue() << endl;
	//Value v2 = 56;
	//cout << v2.getValue() << endl;
	return 0;
}