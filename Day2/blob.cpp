#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Blob
{
public:
	template <typename... Args>
	Blob(Args&&... args) : _v({ forward<Args>(args)... }) {}
	void print()
	{
		for (auto item : _v)
		{
			cout << item << endl;
		}
	}
private:
	vector<string> _v;
};

int main()
{
	const char* shapes[] = { "Circle", "Triangle", "Square" };
	Blob b1(shapes);
	b1.print();
	return 0;
}