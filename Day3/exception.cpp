#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Banana : public exception
{
public:
	Banana(int number, const char* message): errorNo(number), errorMessage(message){}
	const char* what() const throw()
	{
		return errorMessage;
	}
private:
	int errorNo;
	const char* errorMessage;
};

void faultyFunc(int age)
{
	if (age >= 18)
	{
		cout << "Access granted - You are old enough." << endl;
	}
	else
	{
		throw Banana(23, "You are to young");
	}
}

int main()
{
	try
	{
		faultyFunc(15);
	}
	catch (Banana error)
	{
		cout << error.what() << endl;
	}
	return 0;
}