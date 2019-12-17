#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> numbers = { 1, 2, 3, 4 };
	numbers.push_back(5);
	numbers[2] = 99;
	for (auto value : numbers)
	{
		cout << value << endl;
	}
	return 0;
}